#ifndef BTNMANAGECARD_H
#define BTNMANAGECARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

using namespace std;

class Btnmanagecard : public QGraphicsPixmapItem{
public:
    Btnmanagecard();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BTNMANAGECARD_H
