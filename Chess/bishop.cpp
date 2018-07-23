#include "bishop.h"
#include "game.h"

extern Game *game;
Bishop::Bishop(QString team,QGraphicsItem *parent) : Figure (team,parent)
{
    SetImage();
}

void Bishop::SetImage()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/Resources/bishop1.png"));
    else
        setPixmap(QPixmap(":/Resources/bishop.png"));
}

void Bishop::Moves()
{
    location.clear();
    int row = this->GetCurrentBox()->GetRow();
    int col = this->GetCurrentBox()->GetCol();
    QString team = this->GetSide();

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
