#ifndef SELECTCARD_H
#define SELECTCARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <QString>
#include <QObject>
using namespace std;

class Selectcard : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Selectcard(QString str);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QString string;
    double ratio;
public slots:
    void setratio();
};

#endif // SELECTCARD_H
