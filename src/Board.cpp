#include "raylib.h"
#include "Board.hpp"

Board::Board() : boardSize(GetScreenHeight() * 8 / 9), padding(GetScreenWidth() - boardSize)
{
}

Board::~Board()
{
}

void Board::ShowBoard()
{
    this->cellSize = this->boardSize / 8;
    Color color;
    for (int i = 0; i < 64; i++)
    {
        if ((i + (i / 8)) & 1)
            color = WHITE;
        else
            color = GRAY;
        DrawRectangle(
            (i % 8) * this->cellSize + this->padding / 2,
            (i / 8) * this->cellSize + this->cellSize / 2,
            this->cellSize, this->cellSize, color);
    }
}

void Board::SetBoard()
{
    for (int i = 0; i < 5; i++)
    {
        this->board[i] = -i - 2;
        this->board[56 + i] = i + 2;
    }
    for (int i = 5; i < 8; i++)
    {
        this->board[i] = i - 9;
        this->board[56 + i] = 9 - i;
    }
    for (int i = 8; i < 16; i++)
    {
        this->board[i] = -1;
        this->board[40 + i] = 1;
    }
}
