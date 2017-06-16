#ifndef WENSONPHOTO_H
#define WENSONPHOTO_H

#include<QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Myunit.h"

class Wensonphoto: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Wensonphoto(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    Myunit *un;
};

#endif // WENSONPHOTO_H
