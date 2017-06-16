#ifndef FIREBYHERO_H
#define FIREBYHERO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Firebyhero: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Firebyhero(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // FIREBYHERO_H
