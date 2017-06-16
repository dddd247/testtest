#ifndef BTNDRAWCARD_H
#define BTNDRAWCARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include <iostream>

using namespace std;

class Btndrawcard : public QGraphicsPixmapItem
{
public:
    Btndrawcard();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int position;
    int order;

};


#endif // BTNDRAWCARD_H
