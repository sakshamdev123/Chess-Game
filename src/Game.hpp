#pragma once
#include "Board.hpp"

class Game
{
public:
    Game();
    ~Game();
    void SetDisplay();
    void ResetBoard();
    void StartMenu();
    void StartGame(const int &t);
    void QuitGame();
    void DisplayResult();
    void ResizeBoard();
    void HandleEvents();

private:
    int WINDOW_SIZE;
    int state;
    Board board;
};