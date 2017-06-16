#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include "Game.h"
#include "Enemy.h"
#include "Shiehmphoto.h"
extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

    QPixmap arrow;
    arrow.load(":images/arrow.jpg");
    arrow = arrow.scaled(30,30,Qt::KeepAspectRatio);
    setPixmap(arrow);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(25);
}

void Bullet::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Myunit)||typeid(*(colliding_items[i])) == typeid(Enemy)){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    int STEP_SIZE = 30;
    double theta = rotation();
    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
    setPos(x()+dx+0.8, y()+dy+2.5);

}
