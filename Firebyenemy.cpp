#include "Firebyenemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "Game.h"
#include "Enemy.h"

extern Game * game;

Firebyenemy::Firebyenemy(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

    QPixmap arrow;
    arrow.load(":images/bluefire.jpg");
    arrow = arrow.scaled(15,15,Qt::KeepAspectRatio);
    setPixmap(arrow);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
}

void Firebyenemy::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Base)){
            scene()->removeItem(this);
            game->h1->decrease();
            delete this;
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Myunit)){
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

