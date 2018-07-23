#include "king.h"
#include "game.h"

extern Game *game;
King::King(QString team,QGraphicsItem *parent) : Figure(team,parent)
{
    SetImage();
}

void King::SetImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/Resources/king1.png"));
    else
        setPixmap(QPixmap(":/Resources/king.png"));
}

void King::Moves()
{
    location.clear();
    int row = this->GetCurrentBox()->GetRow();
    int col = this->GetCurrentBox()->GetCol();
    int i,j;
    QString team = this->GetSide();

//Up left
    i = row - 1;
    j = col - 1;
    if(col > 0 && row > 0 && !(game->GetBox(i,j)->GetChessPieceColor() == team)) {
        location.append(game->GetBox(i,j));
    }
//Up right
    i = row - 1;
    j = col + 1;
    if(col < 7 && row > 0 && !(game->GetBox(i,j)->GetChessPieceColor() == team)) {
        location.append(game->GetBox(i,j));
    }
//Up
    i = row - 1;
    j = col;
    if(row >0 && !(game->GetBox(i,j)->GetChessPieceColor() == team)) {
        location.append(game->GetBox(i,j));
    }
//Down
    i = row + 1;
    j = col;
    if(row<7 && !(game->GetBox(i,j)->GetChessPieceColor() == team)) {
        location.append(game->GetBox(i,j));
    }
//Left
    i = row;
    j = col - 1;
    if(col>0 && !(game->GetBox(i,j)->GetChessPieceColor() == team)) {
        location.append(game->GetBox(i,j));
    }
//Right
    i = row;
    j = col + 1;
    if(col<7 && !(game->GetBox(i,j)->GetChessPieceColor() == team)) {
        location.append(game->GetBox(i,j));
    }
//Down left
    i = row + 1;
    j = col - 1;
    if(col > 0 && row < 7  && !(game->GetBox(i,j)->GetChessPieceColor() == team)) {
        location.append(game->GetBox(i,j));
    }
//Down right
    i = row + 1;
    j = col + 1;
    if(col < 7 && row < 7 && !(game->GetBox(i,j)->GetChessPieceColor() == team)) {
        location.append(game->GetBox(i,j));
    }
}
