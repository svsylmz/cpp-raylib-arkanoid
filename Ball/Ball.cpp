#include "Ball.h"
#include "raylib.h"

Ball::Ball() = default;

Ball::Ball(int windowWidth, int windowHeight, float playerSizeY)
{
    position = {(float)windowWidth / 2, (float)windowHeight - playerSizeY * 2 - radius};
}

void Ball::draw() const {
    DrawCircleV(position, radius, _color);
}

void Ball::move(int windowWidth, float dT, Vector2 playerPosition, Vector2 playerSize, Rectangle playerBounds) {
    if(IsKeyPressed(KEY_SPACE)) active = true;
    if(active)
    {
        position.x += speed.x * dT;
        position.y -= speed.y * dT;
        limits(windowWidth);
        collisionWithPlayer(playerPosition, playerSize, playerBounds);
    }
}

void Ball::limits(int windowWidth) {
    if (((position.x + radius) >= (float)windowWidth) || ((position.x - radius) <= 0)) speed.x *= -1;
    if ((position.y + radius) <= 0) speed.y *= -1;
}

void Ball::collisionWithPlayer(Vector2 playerPosition, Vector2 playerSize, Rectangle playerBounds) {
    if (CheckCollisionCircleRec(position, radius, playerBounds))
    {
        speed.y *= -1;
        speed.x = (position.x - (playerPosition.x + playerSize.x / 8));
    }
}

Ball::~Ball() = default;
