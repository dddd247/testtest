#ifndef HPHSIEHPHOTO_H
#define HPHSIEHPHOTO_H

#include<QObject>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Myunit.h"

class Hphsiehphoto: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Hphsiehphoto(QString str, QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Myunit * un;
    double ratio;
    QString string;
    double defence;
    double walkspeed;
    int attackarea;
    int mana;

};

#endif // HPHSIEHPHOTO_H
