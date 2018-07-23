#ifndef KING_H
#define KING_H
#include "figure.h"

class King : public Figure
{
public:
    King(QString team , QGraphicsItem *parent = nullptr);
    void SetImage();
    void Moves();
};

#endif // KING_H
