#ifndef WALLBALL_BALL_H
#define WALLBALL_BALL_H

#include "raylib.h"

class Ball
{
public:
    Ball();
    Ball(int windowWidth, int windowHeight, float playerSizeY);
    ~Ball();

    void draw() const;
    void move(int windowWidth, float dT, Vector2 playerPosition, Vector2 playerSize, Rectangle playerBounds);
    void limits(int windowWidth);
    void collisionWithPlayer(Vector2 playerPosition, Vector2 playerSize, Rectangle playerBounds);

    float radius = 10.0f;
    Vector2 position = {};
    Vector2 speed = {0, 420.0f};
    bool active = false;


private:
    Color _color = WHITE;
};


#endif //WALLBALL_BALL_H
