#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "chessboard.h"
#include "chessbox.h"
#include "figure.h"

class Game : public QGraphicsView
{
private:
    ChessBox *boxes[8][8];
    QGraphicsScene *gameScene;
    ChessBoard *chessBoard;
    Figure *figure;
    QString Turn;
public:
    Game(QWidget *parent =nullptr);
    void Start();
    void AddToScene(QGraphicsItem *item);
    void RemoveFromScene(QGraphicsItem *item);
    void ChangeTurn();
    void SetTurn(QString turn);
    void SetBox(ChessBox *box, int x, int y);
    ChessBox* GetBox(int x, int y);
    Figure* GetFigure();
    QString GetTurn();
    void SetFigure(Figure *fig);
};

#endif // GAME_H
