#ifndef BTNMERGE_H
#define BTNMERGE_H

#include <QString>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

class Btnmerge : public QGraphicsPixmapItem{
public:
    Btnmerge();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BTNMERGE_H
