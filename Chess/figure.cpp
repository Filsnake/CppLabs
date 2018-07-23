#include "figure.h"
#include "game.h"

extern Game *game;
Figure::Figure(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    isPlaced = true;
    firstMove = true;
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this == game->GetFigure()){
       game->SetFigure(nullptr);
       return;
    }
    if((!GetIsPlaced() )|| ( (game->GetTurn() != this->GetSide())&& (!game->GetFigure())) )
        return;
    if(!game->GetFigure()){
        game->SetFigure(this);
        game->GetFigure()->Moves();
    }
    else if(this->GetSide() != game->GetFigure()->GetSide()){
        this->GetCurrentBox()->mousePressEvent(event);
    }
}

void Figure::SetCurrentBox(ChessBox *box)
{
    currentBox = box;
}

void Figure::SetFirstMove(bool TF)
{
    firstMove = TF;
}

void Figure::SetIsPlaced(bool value)
{
    isPlaced = value;
}

QList<ChessBox *> Figure::GetLocation()
{
    return location;
}

QString Figure::GetSide()
{
    return side;
}

ChessBox* Figure::GetCurrentBox()
{
    return currentBox;
}

bool Figure::GetIsPlaced()
{
    return isPlaced;
}
