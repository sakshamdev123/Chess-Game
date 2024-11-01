#pragma once
#include "raylib.h"

class Menu
{
public:
    Menu();
    ~Menu();
    void DrawCell(const int &x, const int &y);
    void ShowMenu();
    int HandleMouseClick(const int &x_pos, const int &y_pos);
    int menuHeight;
    int menuWidth;

private:
    int fontSize;
    Color fontColor;
};