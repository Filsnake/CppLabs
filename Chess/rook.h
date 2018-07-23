#ifndef ROOK_H
#define ROOK_H
#include "figure.h"

class Rook : public Figure
{
public:
    Rook(QString team , QGraphicsItem *parent = nullptr);
    void SetImage();
    void Moves();
};

#endif // ROOK_H
