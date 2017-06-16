#include "Firebyunit.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "Game.h"
#include "Enemy.h"

extern Game * game;

Firebyunit::Firebyunit(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

    QPixmap arrow;
    arrow.load(":images/firebyunit.png");
    arrow = arrow.scaled(15,15,Qt::KeepAspectRatio);
    setPixmap(arrow);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
}

void Firebyunit::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Tower)){
            scene()->removeItem(this);
            game->h2->decrease();
            delete this;
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    int STEP_SIZE = 30;
    double theta = rotation(); // degrees
    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
    setPos(x()+dx+0.4, y()+dy+2);
}

