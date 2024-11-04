#include "Pieces.hpp"

Texture2D Pieces::pieceImages[13] = {};

Pieces::Pieces() : cellSize(GetScreenHeight() / 9), padding(GetScreenWidth() - GetScreenHeight() * 8 / 9)
{
    for (int i = -6; i < 7; i++)
    {
        if (this->pieceImages[i + 6].id == 0)
        {
            switch (i)
            {
            case -6:
                this->pieceImages[i + 6] = LoadTexture("assets/black-king.png");
                break;
            case -5:
                this->pieceImages[i + 6] = LoadTexture("assets/black-queen.png");
                break;
            case -4:
                this->pieceImages[i + 6] = LoadTexture("assets/black-bishop.png");
                break;
            case -3:
                this->pieceImages[i + 6] = LoadTexture("assets/black-knight.png");
                break;
            case -2:
                this->pieceImages[i + 6] = LoadTexture("assets/black-rook.png");
                break;
            case -1:
                this->pieceImages[i + 6] = LoadTexture("assets/black-pawn.png");
                break;

            case 6:
                this->pieceImages[i + 6] = LoadTexture("assets/white-king.png");
                break;
            case 5:
                this->pieceImages[i + 6] = LoadTexture("assets/white-queen.png");
                break;
            case 4:
                this->pieceImages[i + 6] = LoadTexture("assets/white-bishop.png");
                break;
            case 3:
                this->pieceImages[i + 6] = LoadTexture("assets/white-knight.png");
                break;
            case 2:
                this->pieceImages[i + 6] = LoadTexture("assets/white-rook.png");
                break;
            case 1:
                this->pieceImages[i + 6] = LoadTexture("assets/white-pawn.png");
                break;

            default:
                break;
            }
        }
    }
}

Pieces::~Pieces()
{
    this->unloadPiecesImages();
}

void Pieces::ShowPieces(const char board[])
{
    for (int i = 0; i < 64; i++)
    {
        if ((bool)board[i])
            DrawTextureEx(
                this->pieceImages[(int)board[i] + 6],
                {(i % 8) * this->cellSize + (float)this->padding / 2,
                 (i / 8) * this->cellSize + (float)this->cellSize / 2},
                0, 0.5f, WHITE);
    }
}

void Pieces::ShowPieces()
{
}

void Pieces::unloadPiecesImages()
{
    for (int i = 0; i < 13; i++)
    {
        UnloadTexture(this->pieceImages[i]);
    }
}
