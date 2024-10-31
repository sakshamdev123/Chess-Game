#pragma once
#include <vector>

class Board
{
public:
    Board();
    ~Board();
    void DrawCell(const int &posX, const int &posY, const Color &color);
    void ShowBoard();
    int boardSize;
    int padding;

private:
    int cellSize;
    std::vector<char> board;
    void SetBoard();
};