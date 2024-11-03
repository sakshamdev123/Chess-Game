#pragma once

class Timer
{
public:
    Timer();
    ~Timer();
    void ShowTimer();
    void ToggleTimer();
    void CalculateTime(const int &time, char timeRemaining[]);
    void SetTimer(const int &time);

    int startTime;
    bool gameOver;
    int playerOneTimerPadding;
    int playerTwoTimerPadding;
    int fontSize;

private:
    int playerOneTime;
    int playerTwoTime;
    bool turn;
};