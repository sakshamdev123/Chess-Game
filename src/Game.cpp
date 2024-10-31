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
    case 1:
        board.ShowBoard();
        break;

    default:
        break;
    }
}

void Game::ResetBoard()
{
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

void Game::ResizeBoard()
{
    board.boardSize = GetScreenHeight() * 8 / 9;
    board.padding = GetScreenWidth() - board.boardSize;
}

void Game::HandleEvents()
{
    if (IsKeyPressed(KEY_ONE) && (this->state == 0 || this->state == 2))
        StartGame(5);
    if (IsKeyPressed(KEY_TWO) && (this->state == 0 || this->state == 2))
        StartGame(10);
    if (IsKeyPressed(KEY_THREE) && (this->state == 0 || this->state == 2))
        StartGame(15);
    if (IsKeyPressed(KEY_FOUR) && this->state == 2)
        StartMenu();
    if (IsKeyPressed(KEY_Q) && this->state == 1)
        QuitGame();
    if (IsWindowResized())
        ResizeBoard();
}
