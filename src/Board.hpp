#pragma once
#include <vector>

class Board
{
public:
    Board();
    ~Board();
    void ShowBoard();
    int boardSize;
    int padding;

private:
    int cellSize;
    std::vector<char> board;
    void SetBoard();
};