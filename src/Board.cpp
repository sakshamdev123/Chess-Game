#include "raylib.h"
#include "Board.hpp"

Board::Board() : boardSize(GetScreenHeight()*8/9), padding(GetScreenWidth()-boardSize)
{
}

Board::~Board()
{
}

void Board::DrawCell(const int &posX, const int &posY, const Color &color)
{
    DrawRectangle(posX * cellSize + padding / 2, posY * cellSize + cellSize / 2, cellSize, cellSize, color);
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
        this->DrawCell(i % 8, i / 8, color);
    }
}

void Board::SetBoard()
{
    this->board = {
        -2, -3, -4, -5, -6, -4, -3, -2,
        -1, -1, -1, -1, -1, -1, -1, -1,
         0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,
         1,  1,  1,  1,  1,  1,  1,  1,
         2,  3,  4,  5,  6,  4,  3,  2
    };
}
