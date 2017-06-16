#ifndef FIREBYUNIT_H
#define FIREBYUNIT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Firebyunit: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Firebyunit(QGraphicsItem * parent=0);
public slots:
    void move();
};
#endif // FIREBYUNIT_H
