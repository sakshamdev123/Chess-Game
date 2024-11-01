#include "raylib.h"
#include "Game.hpp"
#include "Board.hpp"
#include <iostream>

Game::Game() : state(0), board()
{
}

Game::~Game()
{
}

void Game::SetDisplay()
{
    switch (state)
    {
    case 0:
        this->menu.ShowMenu();
        break;
    case 1:
        this->board.ShowBoard();
        break;

    default:
        break;
    }
}

void Game::StartMenu()
{
    this->state = 0;
}

void Game::StartGame(const int &t)
{
    this->state = 1;
    std::cout << t;
}

void Game::QuitGame()
{
    this->state = 2;
}

void Game::DisplayResult()
{
    this->state = 3;
}

void Game::HandleResize()
{
    int screenHeight = GetScreenHeight();
    int screenWidth = GetScreenWidth();
    this->menu.menuHeight = screenHeight;
    this->menu.menuWidth = screenWidth;
    this->board.boardSize = screenHeight * 8 / 9;
    this->board.padding = screenWidth - this->board.boardSize;
}

void Game::HandleEvents()
{
    if (IsKeyPressed(KEY_ONE) && (this->state == 0 || this->state == 2))
        this->StartGame(5);
    if (IsKeyPressed(KEY_TWO) && (this->state == 0 || this->state == 2))
        this->StartGame(10);
    if (IsKeyPressed(KEY_THREE) && (this->state == 0 || this->state == 2))
        this->StartGame(15);
    if (IsKeyPressed(KEY_FOUR) && this->state == 2)
        this->StartMenu();
    if (IsKeyPressed(KEY_Q) && this->state == 1)
        this->QuitGame();

    if (IsWindowResized())
        this->HandleResize();

    if (IsMouseButtonDown(0))
    {
        int x_pos = GetMouseX();
        int y_pos = GetMouseY();
        switch (this->state)
        {
        case 0:
            this->StartGame(menu.HandleMouseClick(x_pos, y_pos));
            break;

        default:
            break;
        }
    }
}
