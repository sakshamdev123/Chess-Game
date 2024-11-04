#include "raylib.h"

class Pieces
{
public:
    Pieces();
    ~Pieces();
    void ShowPieces(const char board[]);
    void ShowPieces();

    int cellSize;
    int padding;

    static Texture2D pieceImages[13];

private:
    void unloadPiecesImages();
};