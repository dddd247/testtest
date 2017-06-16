#ifndef DRAWCARD_H
#define DRAWCARD_H

#include<QObject>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Drawcard: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Drawcard();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // DRAWCARD_H
