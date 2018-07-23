#include "chessbox.h"
#include "game.h"

extern Game *game;

ChessBox::ChessBox(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,60,60);
    QGraphicsRectItem::setZValue(-1);
    SetHasChessPiece(false);
    SetChessPieceColor("NONE");
    currentFigure = nullptr;
}

void ChessBox::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(currentFigure == game->GetFigure() && currentFigure){
        currentFigure->mousePressEvent(event);
        return;
    }
    if(game->GetFigure()){
        if(this->GetChessPieceColor() == game->GetFigure()->GetSide())
            return;
        QList <ChessBox *> movLoc = game->GetFigure()->GetLocation();
        int check = 0;
        for(int i = 0, n = movLoc.size(); i < n;i++) {
            if(movLoc[i] == this) {
                check++;
            }
        }
        if(check == 0)
            return;
        game->GetFigure()->SetFirstMove(false);
        if(this->GetHasChessPiece()){
            this->currentFigure->SetIsPlaced(false);
            this->currentFigure->SetCurrentBox(nullptr);
            game->RemoveFromScene(this->currentFigure);
        }
        game->GetFigure()->GetCurrentBox()->SetHasChessPiece(false);
        game->GetFigure()->GetCurrentBox()->currentFigure = nullptr;
        PlacePiece(game->GetFigure());

        game->SetFigure(nullptr);
        game->ChangeTurn();
    }
    else if(this->GetHasChessPiece())
    {
        this->currentFigure->mousePressEvent(event);
    }
}

void ChessBox::PlacePiece(Figure *piece)
{
    piece->setPos(x()+30- piece->pixmap().width()/2  ,y()+30-piece->pixmap().width()/2);
    piece->SetCurrentBox(this);
    SetHasChessPiece(true,piece);
    currentFigure = piece;
}

void ChessBox::SetHasChessPiece(bool value, Figure *piece)
{
    hasChessPiece = value;
    if(value)
        SetChessPieceColor(piece->GetSide());
    else
        SetChessPieceColor("NONE");
}

void ChessBox::SetChessPieceColor(QString value)
{
    chessPieceColor = value;
}

void ChessBox::SetRow(int row)
{
    rowLoc = row;
}

void ChessBox::SetCol(int col)
{
    colLoc = col;
}

int ChessBox::GetRow()
{
    return rowLoc;
}

int ChessBox::GetCol()
{
    return colLoc;
}

QString ChessBox::GetChessPieceColor()
{
    return chessPieceColor;
}

bool ChessBox::GetHasChessPiece()
{
    return hasChessPiece;
}
