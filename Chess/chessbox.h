#ifndef CHESSBOX_H
#define CHESSBOX_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class ChessPiece;
class ChessBox : public QGraphicsRectItem {
private:
    int rowLoc;
    int colLoc;
    bool hasChessPiece;
    Figure *currentFigure;
    QString chessPieceColor;
public:
    ChessBox(QGraphicsItem *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void PlacePiece(Figure *piece = nullptr);
    void SetHasChessPiece(bool value, Figure *piece = nullptr);
    void SetChessPieceColor(QString value);
    void SetRow(int row);
    void SetCol(int col);
    int GetRow();
    int GetCol();
    QString GetChessPieceColor();
    bool GetHasChessPiece();
};

#endif // CHESSBOX_H
