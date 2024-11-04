#pragma once
#include "Board.hpp"
#include "Menu.hpp"
#include "Header.hpp"
#include "Timer.hpp"
#include "Pieces.hpp"

class Game
{
public:
    Game();
    ~Game();
    void SetDisplay();
    void HandleEvents();

private:
    void HandleResize();
    void StartMenu();
    void StartGame(const int &time);
    void QuitGame();
    void DisplayResult();
    void TogglePlayer();
    int WINDOW_SIZE;
    int state;
    bool playerTurn;
    Board board;
    Menu menu;
    Header header;
    Timer timer;
    Pieces pieces;
};