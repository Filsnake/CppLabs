#ifndef PAWN_H
#define PAWN_H
#include "figure.h"

class Pawn : public Figure
{
public:
    Pawn(QString team,QGraphicsItem *parent = nullptr);
    void SetImage();
    void Moves();
};

#endif // PAWN_H
