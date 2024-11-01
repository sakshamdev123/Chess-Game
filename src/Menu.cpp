#include "Menu.hpp"
#include "raylib.h"

Menu::Menu() : menuHeight(GetScreenHeight()),
               menuWidth(GetScreenWidth()),
               fontSize(GetScreenWidth() / 15),
               fontColor(WHITE)
{
}

Menu::~Menu()
{
}

void Menu::DrawCell(const int &x, const int &y)
{
    DrawRectangle(
        this->menuWidth / 2 - 3 * this->fontSize,
        this->menuHeight / 4 + x * this->fontSize,
        7 * this->fontSize,
        this->menuHeight / 8,
        LIME
    );
    char message[] = "New 00 min Game";
    switch (y)
    {
    case 5:
        message[5] = '5';
        break;
    case 10:
        message[4] = '1';
        break;
    case 15:
        message[4] = '1';
        message[5] = '5';
        break;
    default:
        break;
    }
    DrawText(
        message,
        this->menuWidth / 2 - 2 * this->fontSize,
        this->menuHeight / 4 + (x + 1) * this->fontSize,
        this->fontSize / 2,
        this->fontColor
    );
}

void Menu::ShowMenu()
{
    DrawText(
        "CHESS GAME",
        this->menuWidth / 2 - 3 * this->fontSize,
        this->menuHeight / 4,
        this->fontSize,
        this->fontColor
    );
    DrawCell(2, 5);
    DrawCell(5, 10);
    DrawCell(8, 15);
    DrawText(
        "Shortcuts:\n1 -> 5 min match\n2 -> 10 min match\n3 -> 15 min match\nEsc -> Quit Game",
        this->menuWidth * 7 / 8,
        this->menuHeight * 7 / 8,
        this->fontSize / 4,
        this->fontColor
    );
}

int Menu::HandleMouseClick(const int &x_pos, const int &y_pos)
{
    return x_pos + y_pos;
}
