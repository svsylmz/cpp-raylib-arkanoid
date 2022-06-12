#include "raylib.h"
#include "Player/Player.h"
#include "Ball/Ball.h"
#include "Block/Block.h"
#include "const.h"

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "WALL BALL");

    Player Player(WINDOW_WIDTH, WINDOW_HEIGHT);
    Ball Ball(WINDOW_WIDTH, WINDOW_HEIGHT, Player.size.y);
    Block Blocks[BLOCK_COLUMN][BLOCK_ROW];

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        const float dT = GetFrameTime();

        Player.control(WINDOW_WIDTH, dT);
        Ball.move(WINDOW_WIDTH, dT, Player.position, Player.size, Player.bounds);

        BeginDrawing();
        ClearBackground(BLACK);

        Player.draw();
        Ball.draw();

        for (int i = 0; i < BLOCK_COLUMN; i++)
        {
            for (int j = 0; j < BLOCK_ROW; j++)
            {
                Blocks[i][j].createBlock(i, j);
                if (Blocks[i][j].active && Block::collisionWithBall(Ball.position, Ball.radius, Blocks[i][j].bounds))
                {
                    Blocks[i][j].active = false;
                    Ball.speed.y *= -1;
                    break;
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
}
