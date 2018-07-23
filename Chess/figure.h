#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class ChessBox;
class Figure : public QGraphicsPixmapItem
{
protected:
    QString side;
    ChessBox *currentBox;
    bool isPlaced;
    bool firstMove;
    QList <ChessBox *> location;
public:
    Figure(QString team, QGraphicsItem *parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void SetCurrentBox(ChessBox *box);
    void SetFirstMove(bool TF);
    void SetIsPlaced(bool value);
    bool BoxSetting(ChessBox *box);
    QList<ChessBox *> GetLocation();
    virtual void SetImage()= 0;
    virtual void Moves() = 0;
    QString GetSide();
    ChessBox *GetCurrentBox();
    bool GetIsPlaced();
};

#endif // FIGURE_H
