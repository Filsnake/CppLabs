#ifndef KNIGHT_H
#define KNIGHT_H
#include "figure.h"

class Knight : public Figure
{
public:
    Knight(QString team , QGraphicsItem *parent = nullptr);
    void SetImage();
    void Moves();
};

#endif // KNIGHT_H
