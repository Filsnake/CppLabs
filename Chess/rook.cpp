#include "rook.h"
#include "game.h"

extern Game *game;
Rook::Rook(QString team,QGraphicsItem *parent) : Figure(team,parent)
{
    SetImage();
}

void Rook::SetImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/Resources/rook1.png"));
    else
        setPixmap(QPixmap(":/Resources/rook.png"));
}

void Rook::Moves()
{
    location.clear();
    int row = this->GetCurrentBox()->GetRow();
    int col = this->GetCurrentBox()->GetCol();
    QString team = this->GetSide();

//For up
    for(int i = row-1,j = col; i >= 0 ; i--) {
       if(game->GetBox(i,j)->GetChessPieceColor() == team )
           break;
       else
           location.append(game->GetBox(i,j));
    }
//For Down
    for(int i = row+1,j = col; i <= 7 ; i++) {
        if(game->GetBox(i,j)->GetChessPieceColor() == team )
            break;
        else
            location.append(game->GetBox(i,j));
    }
//For left
    for(int i = row,j = col-1; j >= 0 ; j--) {
        if(game->GetBox(i,j)->GetChessPieceColor() == team )
            break;
        else
            location.append(game->GetBox(i,j));
    }
//For Right
    for(int i = row,j = col+1; j <= 7 ; j++)
        if(game->GetBox(i,j)->GetChessPieceColor() == team )
            break;
        else
            location.append(game->GetBox(i,j));
}
