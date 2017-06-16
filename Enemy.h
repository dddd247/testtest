#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsRectItem>
#include <QString>
class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(int ra, QString str, double def, double walk);
    void rotateToPoint(QPointF p);
    void attack();
    double distanceTo(QGraphicsItem * item);
public slots:
    void move_forward();
    void setratio();
    void target();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
    double ratio;
    QString string;
    double defence;
    double walkspeed;

    QGraphicsPolygonItem * area;
    QPointF attack_dest;
    bool has_target;

};

#endif // ENEMY_H
