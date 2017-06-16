#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QLineF>
#include "Bullet.h"
#include "Firebyunit.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include "Myunit.h"
#include <QDebug>
extern Game * game;

Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){

    QPixmap tower;
    tower.load(":/images/tower.png");
    tower = tower.scaled(100,100,Qt::KeepAspectRatio);
    setPixmap(tower);

    QVector<QPointF> points;
    points << QPoint(10,0) << QPoint(20,0) << QPoint(30,10) << QPoint(30,20) << QPoint(20,30)
           << QPoint(10,30) << QPoint(0,20) << QPoint(0,10);
    int SCALE_FACTOR = 19;
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->setPen(QPen(Qt::DotLine));

    QPointF poly_center(15,15);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF tower_center(x()+44,y()+44);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());


    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(200);

    attack_dest = QPointF(0,0);
    has_target = false;
}

double Tower::distanceTo(QGraphicsItem *item){

    QLineF ln(this->pos(),item->pos());
    return ln.length();
}

void Tower::fire(){
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+44,y()+44);
    QLineF ln(QPointF(x()+44,y()+44),attack_dest);
    int angle = -1 * ln.angle();
    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Tower::aquire_target(){

    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();
    has_target = false;
    double closest_dist = 300;
    QPointF closest_pt(0,0);
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){
        Myunit * enemy = dynamic_cast<Myunit *>(colliding_items[i]);
        if (enemy){
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
        fire();
    }
    if (game->h2->getHealth()<=0){
        game->decidewinorlose();
        game->scene->removeItem(this);
        delete this;
    }
}


