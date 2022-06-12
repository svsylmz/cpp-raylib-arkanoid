#ifndef WALLBALL_PLAYER_H
#define WALLBALL_PLAYER_H

#include "raylib.h"

class Player
{
public:
    Player(int windowWidth, int windowHeight);
    ~Player();

    void draw();
    void control(int windowWidth, float dT);

    Vector2 size = {100, 20};
    Vector2 position = {};
    float speed = 300.0f;
    Rectangle bounds = {};
    float health = 3;

private:
    Color _color = ORANGE;
};

#endif //WALLBALL_PLAYER_H