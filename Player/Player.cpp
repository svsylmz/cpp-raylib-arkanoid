#include "Player.h"
#include "raylib.h"

Player::Player(int windowWidth, int windowHeight)
{
    position = {((float)windowWidth / 2) - size.x / 2, (float)windowHeight - size.y * 2};
}

void Player::draw() {
    DrawRectangleV(position, size, _color);
    bounds = {position.x, position.y, size.x, size.y};
}

void Player::control(int windowWidth, float dT) {
    if (IsKeyDown(KEY_A) && position.x > 0)
        position.x -= speed * dT;
    if (IsKeyDown(KEY_D) && position.x < (float)windowWidth - size.x)
        position.x += speed * dT;
}

Player::~Player() = default;
