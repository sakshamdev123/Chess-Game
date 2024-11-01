#pragma once
#include "Board.hpp"
#include "Menu.hpp"
#include "Header.hpp"

class Game
{
public:
    Game();
    ~Game();
    void SetDisplay();
    void HandleResize();
    void StartMenu();
    void StartGame(const int &t);
    void QuitGame();
    void DisplayResult();
    void HandleEvents();

private:
    int WINDOW_SIZE;
    int state;
    Board board;
    Menu menu;
    Header header;
};