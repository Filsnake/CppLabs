#include "chessboard.h"
#include "chessbox.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"
#include "game.h"

extern Game *game;
ChessBoard::ChessBoard()
{
    SetImage();
    SetUpWhite();
    SetUpBlack();
}

void ChessBoard::SetImage()
{
    setPixmap(QPixmap(":/Resources/board.png"));
    game->AddToScene(this);
}

void ChessBoard::DrawBoxes(int x, int y)
{
    int SHIFT = 60;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            ChessBox *box = new ChessBox();
            game->SetBox(box,i ,j);
            box->SetRow(i);
            box->SetCol(j);
            box->setPos(x+SHIFT*j,y+SHIFT*i);
            game->AddToScene(box);
        }
    }
}

void ChessBoard::AddChessPiece()
{
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            if(i < 2) {
                static int k;
                game->GetBox(i,j)->PlacePiece(black[k]);
                game->AddToScene(black[k++]);
            }
            if(i > 5) {
                static int h;
                game->GetBox(i,j)->PlacePiece(white[h]);
                game->AddToScene(white[h++]);
            }

        }
    }
}

void ChessBoard::SetUpWhite()
{
    Figure *figure;
    for(int i = 0; i < 8; i++) {
        figure = new Pawn("WHITE");
        white.append(figure);
    }
    figure = new Rook("WHITE");
    white.append(figure);
    figure = new Knight("WHITE");
    white.append(figure);
    figure = new Bishop("WHITE");
    white.append(figure);
    figure = new Queen("WHITE");
    white.append(figure);
    figure = new King("WHITE");
    white.append(figure);
    figure = new Bishop("WHITE");
    white.append(figure);
    figure = new Knight("WHITE");
    white.append(figure);
    figure = new Rook("WHITE");
    white.append(figure);
}

void ChessBoard::SetUpBlack()
{
    Figure *figure;
    figure = new Rook("BLACK");
    black.append(figure);
    figure = new Knight("BLACK");
    black.append(figure);
    figure = new Bishop("BLACK");
    black.append(figure);
    figure = new Queen("BLACK");
    black.append(figure);
    figure = new King("BLACK");
    black.append(figure);
    figure = new Bishop("BLACK");
    black.append(figure);
    figure = new Knight("BLACK");
    black.append(figure);
    figure = new Rook("BLACK");
    black.append(figure);
    for(int i = 0; i < 8; i++) {
        figure = new Pawn("BLACK");
        black.append(figure);
    }
}
