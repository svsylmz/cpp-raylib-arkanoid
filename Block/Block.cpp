#include "Block.h"
#include "../Ball/Ball.h"
#include "raylib.h"
#include "../const.h"

Ball Ball;

Block::Block() {
    _blockOffset = (_blockSpace / 2) + (((float)WINDOW_WIDTH - _blockFullWidth * BLOCK_COLUMN) / 2);
    generateColors();
}

void Block::generateColors() {
    for (auto & blockColor : _blockColors)
        blockColor = (Color){(unsigned char)GetRandomValue(20, 250), (unsigned char)GetRandomValue(30, 220), (unsigned char)GetRandomValue(10, 180), 255};
}

void Block::createBlock(int i, int j) {
    if(active) {
        Rectangle block = {_blockFullWidth * (float)i + _blockOffset, _blockFullHeight * (float)j + _blockSpace, _blockSize.x, _blockSize.y};
        DrawRectangleV({block.x, block.y}, {block.width, block.height}, _blockColors[i]);
        bounds = {block.x, block.y, block.width, block.height};
    }
}

bool Block::collisionWithBall(Vector2 ballPosition, float ballRadius, Rectangle blockBounds) {
    if (CheckCollisionCircleRec(ballPosition, ballRadius, blockBounds)) return true;
    else return false;
}

Block::~Block() = default;
