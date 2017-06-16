#ifndef BTNSTART_H
#define BTNSTART_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

using namespace std;

class Btnstart : public QGraphicsPixmapItem
{
public:
    Btnstart();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BTNSTART_H
