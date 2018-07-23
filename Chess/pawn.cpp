#include "pawn.h"
#include "game.h"

extern Game *game;
Pawn::Pawn(QString team,QGraphicsItem *parent) : Figure(team,parent)
{
    SetImage();
    firstMove = true;
}

void Pawn::SetImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/Resources/pawn1.png"));
    else
        setPixmap(QPixmap(":/Resources/pawn.png"));
}

void Pawn::Moves()
{
    location.clear();
    int row = this->GetCurrentBox()->GetRow();
    int col = this->GetCurrentBox()->GetCol();
    int i, j;
    if(this->GetSide() == "WHITE") {
        i = row - 1;
        j = col - 1;
        if(col > 0 && row > 0 && game->GetBox(i,j)->GetChessPieceColor() == "BLACK")
            location.append(game->GetBox(i,j));

        j = col + 1;
        if(col < 7 && row > 0 && game->GetBox(i,j)->GetChessPieceColor() == "BLACK")
            location.append(game->GetBox(i,j));

        j = col;
        if(row>0 && (!game->GetBox(i,j)->GetHasChessPiece())) {
            location.append(game->GetBox(i,j));
            if(firstMove && !game->GetBox(row - 2,j)->GetHasChessPiece())
                location.append(game->GetBox(row - 2,j));
        }
    }
    else {
        i = row + 1;
        j = col - 1;
        if(col > 0 && row < 7 && game->GetBox(i,j)->GetChessPieceColor() == "WHITE")
             location.append(game->GetBox(i,j));

        j = col + 1;
        if(col < 7 && row <  7 && game->GetBox(i,j)->GetChessPieceColor() == "WHITE")
             location.append(game->GetBox(i,j));

        j = col;
        if(row<7 && (!game->GetBox(i, j)->GetHasChessPiece())) {
            location.append(game->GetBox(i, j));
            if(firstMove && !game->GetBox((row + 2), j)->GetHasChessPiece())
                location.append(game->GetBox((row + 2), j));
        }
    }
}
