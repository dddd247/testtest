#ifndef FIREBYENEMY_H
#define FIREBYENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Firebyenemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Firebyenemy(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // FIREBYENEMY_H
