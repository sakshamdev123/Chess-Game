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
    char board[64] = {0};

private:
    int cellSize;
};