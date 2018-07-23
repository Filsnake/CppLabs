#include "knight.h"
#include "game.h"

extern Game *game;
Knight::Knight(QString team,QGraphicsItem *parent) : Figure(team,parent)
{
    SetImage();
}

void Knight::SetImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/Resources/horse1.png"));
    else
        setPixmap(QPixmap(":/Resources/horse.png"));
}

void Knight::Moves()
{
    location.clear();
    int row = this->GetCurrentBox()->GetRow();
    int col = this->GetCurrentBox()->GetCol();
    int i ,j;
    QString team  = this->GetSide();

//1st up up left
    i = row - 2;
    j = col - 1;
    if(i >=0 && j>=0 && (game->GetBox(i,j)->GetChessPieceColor() != team) )
        location.append(game->GetBox(i,j));

//2nd up up right
    i = row - 2;
    j = col + 1;
    if(i >=0 && j<=7 && (game->GetBox(i,j)->GetChessPieceColor() != team) )
        location.append(game->GetBox(i,j));

//3rd down down left
    i = row + 2;
    j = col - 1;
    if(i <= 7 && j>=0 && (game->GetBox(i,j)->GetChessPieceColor() != team) )
        location.append(game->GetBox(i,j));

//4th  down down right
    i = row + 2;
    j = col + 1;
    if(i <=7 && j<=7 && (game->GetBox(i,j)->GetChessPieceColor() != team) )
        location.append(game->GetBox(i,j));

//5th left left up
    i = row - 1;
    j = col - 2;
    if(i >=0 && j>=0 && (game->GetBox(i,j)->GetChessPieceColor() != team) )
        location.append(game->GetBox(i,j));

//6th left left down
    i = row + 1;
    j = col - 2;
    if(i <=7 && j>=0 && (game->GetBox(i,j)->GetChessPieceColor() != team) )
        location.append(game->GetBox(i,j));

//7th right right up
    i = row - 1;
    j = col + 2;
    if(i >=0 && j<=7 && (game->GetBox(i,j)->GetChessPieceColor() != team) )
        location.append(game->GetBox(i,j));

//8th right right down
    i = row + 1;
    j = col +  2;
    if(i <=7 && j<=7 && (game->GetBox(i,j)->GetChessPieceColor() != team) )
        location.append(game->GetBox(i,j));
}
