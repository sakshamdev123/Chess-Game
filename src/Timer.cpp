#include "Timer.hpp"
#include "raylib.h"

Timer::Timer()
    : startTime(GetTime()),
      gameOver(false),
      playerOneTimerPadding(100),
      playerTwoTimerPadding(500),
      fontSize(20),
      turn(false)
{
}

Timer::~Timer()
{
}

void Timer::ShowTimer()
{
    char playerOneTimeStr[7];
    char playerTwoTimeStr[7];
    int remainingTime;
    if (!turn)
    {
        remainingTime = this->playerOneTime + this->startTime - GetTime();
        CalculateTime(remainingTime, playerOneTimeStr);
        CalculateTime(playerTwoTime, playerTwoTimeStr);
    }
    else
    {
        remainingTime = this->playerTwoTime + this->startTime - GetTime();
        CalculateTime(playerOneTime, playerOneTimeStr);
        CalculateTime(remainingTime, playerTwoTimeStr);
    }
    if (remainingTime <= 0)
        this->gameOver = true;
    DrawText(playerOneTimeStr, playerOneTimerPadding, 0, this->fontSize, WHITE);
    DrawText(playerTwoTimeStr, playerTwoTimerPadding, 0, this->fontSize, WHITE);
}

void Timer::ToggleTimer()
{
    this->turn = !this->turn;
    if (turn)
        this->playerOneTime = this->playerOneTime + this->startTime - GetTime();
    else
        this->playerTwoTime = this->playerTwoTime + this->startTime - GetTime();
    this->startTime = GetTime();
}

void Timer::CalculateTime(const int &time, char timeRemaining[])
{
    int minutes = time / 60;
    int seconds = time % 60;
    timeRemaining[0] = minutes / 10 + '0';
    timeRemaining[1] = minutes % 10 + '0';
    timeRemaining[2] = ' ';
    timeRemaining[3] = ':';
    timeRemaining[4] = ' ';
    timeRemaining[5] = seconds / 10 + '0';
    timeRemaining[6] = seconds % 10 + '0';
}

void Timer::SetTimer(const int &time)
{
    this->startTime = GetTime();
    this->playerOneTime = time * 60;
    this->playerTwoTime = time * 60;
}
