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
    this->SetBoard();
    Color color;
    for (size_t i = 0; i < 64; i++)
    {
        if ((i + (i / 8)) & 1)
            color = WHITE;
        else
            color = BLACK;
        DrawRectangle(
            (i % 8) * this->cellSize + this->padding / 2,
            (i / 8) * this->cellSize + this->cellSize / 2,
            this->cellSize, this->cellSize, color);
    }
}

void Board::SetBoard()
{
    this->board = {
        -2, -3, -4, -5, -6, -4, -3, -2,
        -1, -1, -1, -1, -1, -1, -1, -1,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1,
        2, 3, 4, 5, 6, 4, 3, 2};
}
