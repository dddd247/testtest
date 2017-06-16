#ifndef BASE_H
#define BASE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Base:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Base(QGraphicsItem * parent=0);
    double distanceTo(QGraphicsItem * item);
    void fire();
    void receiveatk();

public slots:
    void aquire_target();
private:
    QGraphicsPolygonItem * attack_area;
    QGraphicsPolygonItem * receive_area;
    QPointF attack_dest;
    bool has_target;

};

#endif // BASE_H
