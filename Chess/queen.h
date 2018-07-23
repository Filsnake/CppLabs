#ifndef QUEEN_H
#define QUEEN_H
#include "figure.h"

class Queen : public Figure
{
public:
    Queen(QString team , QGraphicsItem *parent = nullptr);
    void SetImage();
    void Moves();
};

#endif // QUEEN_H
