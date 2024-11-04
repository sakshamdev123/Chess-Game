#pragma once

class Board
{
public:
    Board();
    ~Board();
    void ShowBoard();
    void SetBoard();
    int boardSize;
    int padding;

private:
    int cellSize;
    char board[64] = {0};
};