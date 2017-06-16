#ifndef SHIEHMPHOTO_H
#define SHIEHMPHOTO_H
#include<QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Myunit.h"

class Shiehmphoto: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Shiehmphoto(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Myunit * un;
};

#endif // SHIEHMPHOTO_H
