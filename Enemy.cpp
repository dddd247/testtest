#include "Enemy.h"
#include "Myunit.h"
#include "Firebyenemy.h"
#include "Firebyunit.h"
#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QList>
#include <QString>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QLineF>
#include <stdlib.h>
#include <QGraphicsRectItem>
#include "Game.h"

extern Game * game;
Enemy::Enemy(int ra,QString str,double def,double walk){

    ratio=ra;
    string=str;
    defence=def;
    walkspeed=walk;


    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(15);
    QTimer * timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(target()));
    timer1->start(500);


    QVector<QPointF> points;
    points << QPoint(10,0) << QPoint(20,0) << QPoint(30,10) << QPoint(30,20) << QPoint(20,30)
           << QPoint(10,30) << QPoint(0,20) << QPoint(0,10);

    int SCALE_FACTOR = 13;
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    area = new QGraphicsPolygonItem(QPolygonF(points),this);
    area->setPen(QPen(Qt::transparent));

    QPointF poly_center(15,15);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF tower_center(x()+44,y()+44);
    QLineF ln(poly_center,tower_center);
    area->setPos(x()+ln.dx(),y()+ln.dy());

    attack_dest = QPointF(0,0);
    has_target = false;
}

void Enemy::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void Enemy::move_forward(){
    int a=(rand() % 3)-1;
    setPos(x()+walkspeed, y()+2*a);
    if(this->x()>1400) setPos(x()-400, y());
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Firebyunit)||typeid(*(colliding_items[i])) == typeid(Bullet)){
           this->setratio();
        }
    }
    if(ratio<=30){
        scene()->removeItem(this);
        delete this;
    }
}
void Enemy::setratio(){
    this->ratio-=(defence/10);
    QPixmap en;
    en.load(string);
    en = en.scaled(this->ratio,this->ratio,Qt::KeepAspectRatio);
    setPixmap(en);
}
void Enemy::target(){
    QList<QGraphicsItem *> colliding_items = area->collidingItems();
    has_target = false;
    double closest_dist = 300;
    QPointF closest_pt(0,0);
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){

        Base * tower = dynamic_cast<Base *>(colliding_items[i]);
        Myunit * myunit = dynamic_cast<Myunit *>(colliding_items[i]);

        if (tower||myunit){
            double this_dist = distanceTo(colliding_items[i]);
            if (this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }
    if (has_target){
        attack_dest = closest_pt;
        attack();
    }
}
void Enemy::attack(){
    Firebyenemy * bullet = new Firebyenemy();
    bullet->setPos(x()+44,y()+44);
    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}
double Enemy::distanceTo(QGraphicsItem *item){
    QLineF ln(this->pos(),item->pos());
    return ln.length();
}
