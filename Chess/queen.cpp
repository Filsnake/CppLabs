#include "queen.h"
#include "game.h"

extern Game *game;
Queen::Queen(QString team,QGraphicsItem *parent) : Figure(team,parent)
{
    SetImage();
}

void Queen::SetImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/Resources/queen1.png"));
    else
        setPixmap(QPixmap(":/Resources/queen.png"));
}

void Queen::Moves()
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
     for(int i = row,j = col+1; j <= 7 ; j++) {
         if(game->GetBox(i,j)->GetChessPieceColor() == team )
             break;
         else
             location.append(game->GetBox(i,j));
     }
//For upper Left
     for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--) {
         if(game->GetBox(i,j)->GetChessPieceColor() == team )
             break;
         else
             location.append(game->GetBox(i,j));
     }
//For upper right
     for(int i = row-1,j = col+1; i >= 0 && j <= 7; i--,j++) {
         if(game->GetBox(i,j)->GetChessPieceColor() == team )
             break;
         else
             location.append(game->GetBox(i,j));
     }
//For downward right
     for(int i = row+1,j = col+1; i <= 7 && j <= 7; i++,j++) {
         if(game->GetBox(i,j)->GetChessPieceColor() == team )
             break;
         else
             location.append(game->GetBox(i,j));
     }
//For downward left
     for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
         if(game->GetBox(i,j)->GetChessPieceColor() == team )
             break;
         else
             location.append(game->GetBox(i,j));
     }
}
