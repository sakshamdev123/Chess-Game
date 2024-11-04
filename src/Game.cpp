#include "raylib.h"
#include "Game.hpp"
#include "Board.hpp"

Game::Game() : state(0), playerTurn(false)
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
        this->header.ShowHeader();
        this->timer.ShowTimer();
        if (this->timer.gameOver)
            this->state = 3;
        break;
    case 2:
        this->timer.gameOver = false;
        break;
    case 3:
        this->timer.gameOver = false;
        break;

    default:
        break;
    }
}

void Game::StartMenu()
{
    this->state = 0;
}

void Game::StartGame(const int &time)
{
    this->state = 1;
    this->board.SetBoard();
    this->timer.SetTimer(time);
}

void Game::QuitGame()
{
    this->state = 2;
}

void Game::DisplayResult()
{
    this->state = 3;
}

void Game::TogglePlayer()
{
    this->playerTurn = !this->playerTurn;
    this->timer.ToggleTimer();
}

void Game::HandleResize()
{
    int screenHeight = GetScreenHeight();
    int screenWidth = GetScreenWidth();
    this->menu.menuHeight = screenHeight;
    this->menu.menuWidth = screenWidth;
    this->board.boardSize = screenHeight * 8 / 9;
    this->board.padding = screenWidth - this->board.boardSize;
    this->header.headerHeight = screenHeight;
    this->header.headerWidth = screenWidth;
    this->timer.playerOneTimerPadding = screenWidth * 7 / 12 - screenHeight * 4 / 9;
    this->timer.playerTwoTimerPadding = screenWidth * 4 / 12 + screenHeight * 4 / 9;
    this->timer.fontSize = screenHeight / 32;
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
    if (IsKeyPressed(KEY_SPACE) && this->state == 1)
        this->TogglePlayer();

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
