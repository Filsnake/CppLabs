#ifndef BISHOP_H
#define BISHOP_H
#include "figure.h"

class Bishop : public Figure
{
public:
    Bishop(QString team , QGraphicsItem *parent = nullptr);
    void SetImage();
    void Moves();
};

#endif // BISHOP_H
