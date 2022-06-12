#ifndef WALLBALL_BLOCK_H
#define WALLBALL_BLOCK_H

#include "raylib.h"
#include "../const.h"

class Block
{
public:
    explicit Block();
    ~Block();

    void generateColors();
    void createBlock(int i, int j);
    bool active = true;
    Rectangle bounds = {};
    static bool collisionWithBall(Vector2 ballPosition, float ballRadius, Rectangle blockBounds);

private:
    Vector2 _blockSize = {50, 20};
    float _blockSpace = 7.0f;
    float _blockFullWidth = _blockSize.x + _blockSpace;
    float _blockFullHeight = _blockSize.y + _blockSpace;
    float _blockOffset;
    Color _blockColors[BLOCK_COLUMN] = {0};
};


#endif //WALLBALL_BLOCK_H
