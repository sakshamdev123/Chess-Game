#include "Header.hpp"
#include "raylib.h"

Header::Header() : headerHeight(GetScreenHeight()), headerWidth(GetScreenWidth())
{
}

Header::~Header()
{
}

void Header::ShowHeader()
{
    int padding = this->headerWidth - this->headerHeight * 8 / 9;
    DrawRectangle(
        padding / 2,
        0,
        this->headerHeight * 8 / 9,
        this->headerHeight / 18,
        GREEN
    );
    DrawRectangle(
        padding / 2,
        this->headerHeight * 17 / 18,
        this->headerHeight * 8 / 9,
        this->headerHeight / 18,
        GREEN
    );
    DrawText(
        "Shortcuts:\tq -> End Match\tEsc -> Quit Game",
        padding / 2 + 10,
        this->headerHeight * 19 / 20,
        this->headerWidth / 60,
        WHITE
    );
}
