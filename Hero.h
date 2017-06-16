#ifndef HERO_H
#define HERO_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Hero: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Hero();
    void keyPressEvent(QKeyEvent * event);
    void fire();
};


#endif // HERO_H
