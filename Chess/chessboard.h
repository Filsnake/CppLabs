#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "figure.h"

class Game;
class ChessBoard : public QGraphicsPixmapItem
{
private:
    QList <Figure *> white;
    QList <Figure *> black;
public:
    ChessBoard();
    void SetImage();
    void DrawBoxes(int x, int y);
    void AddChessPiece();
    void SetUpWhite();
    void SetUpBlack();
};

#endif // CHESSBOARD_H
