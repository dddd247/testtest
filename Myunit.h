#ifndef MYUNIT_H
#define MYUNIT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsRectItem>
#include <QString>
class Myunit: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Myunit(int ra, QString str, double def, double walk, int atkarea);
    void rotateToPoint(QPointF p);
    void attack();
    double distanceTo(QGraphicsItem * item);
public slots:
    void move_forward();
    void setratio();
    void target();
    void extrafeatureone();
    void extrafeaturetwo();
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
    double ratio;
    QString string;
    double defence;
    double walkspeed;
    int attackarea;

    QGraphicsPolygonItem * area;
    QPointF attack_dest;
    bool has_target;

};

#endif // MYUNIT_H
