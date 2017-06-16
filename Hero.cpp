#include "Hero.h"
#include "Game.h"
#include <QKeyEvent>
#include "Firebyunit.h"
extern Game *game;
Hero::Hero(){
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

void Hero::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
            setPos(x()-10,y());
        }
        else if (event->key() == Qt::Key_Right){
            setPos(x()+10,y());
        }
        else if (event->key() == Qt::Key_Up){
            setPos(x(),y()-10);
        }
        else if (event->key() == Qt::Key_Down){
            setPos(x(),y()+10);
        }
        else if(event->key() == Qt::Key_Space){
        fire();
    }
}

void Hero::fire(){
    Firebyunit * firebyunit = new Firebyunit();
    firebyunit->setPos(x()+45,y()+45);
    QLineF ln(QPointF(x()+45,y()+45),QPointF(x()+45+300,y()+45));
    int angle = -1 * ln.angle();
    firebyunit->setRotation(angle);
    game->scene->addItem(firebyunit);
    Firebyunit * firebyunit2 = new Firebyunit();
    firebyunit2->setPos(x()+45,y()+45);
    QLineF ln2(QPointF(x()+45,y()+45),QPointF(x()+45-300,y()+45));
    int angle2 = -1 * ln2.angle();
    firebyunit2->setRotation(angle2);
    game->scene->addItem(firebyunit2);
    Firebyunit * firebyunit3 = new Firebyunit();
    firebyunit3->setPos(x()+45,y()+45);
    QLineF ln3(QPointF(x()+45,y()+45),QPointF(x()+45,y()+45+300));
    int angle3 = -1 * ln3.angle();
    firebyunit3->setRotation(angle3);
    game->scene->addItem(firebyunit3);
    Firebyunit * firebyunit4 = new Firebyunit();
    firebyunit4->setPos(x()+45,y()+45);
    QLineF ln4(QPointF(x()+45,y()+45),QPointF(x()+45,y()+45-300));
    int angle4 = -1 * ln4.angle();
    firebyunit4->setRotation(angle4);
    game->scene->addItem(firebyunit4);
    Firebyunit * firebyunit5 = new Firebyunit();
    firebyunit5->setPos(x()+45,y()+45);
    QLineF ln5(QPointF(x()+45,y()+45),QPointF(x()+45+210,y()+45+210));
    int angle5 = -1 * ln5.angle();
    firebyunit5->setRotation(angle5);
    game->scene->addItem(firebyunit5);
    Firebyunit * firebyunit6 = new Firebyunit();
    firebyunit6->setPos(x()+45,y()+45);
    QLineF ln6(QPointF(x()+45,y()+45),QPointF(x()+45+210,y()+45-210));
    int angle6 = -1 * ln6.angle();
    firebyunit6->setRotation(angle6);
    game->scene->addItem(firebyunit6);
    Firebyunit * firebyunit7 = new Firebyunit();
    firebyunit7->setPos(x()+45,y()+45);
    QLineF ln7(QPointF(x()+45,y()+45),QPointF(x()+45-210,y()+45+210));
    int angle7 = -1 * ln7.angle();
    firebyunit7->setRotation(angle7);
    game->scene->addItem(firebyunit7);
    Firebyunit * firebyunit8 = new Firebyunit();
    firebyunit8->setPos(x()+45,y()+45);
    QLineF ln8(QPointF(x()+45,y()+45),QPointF(x()+45-210,y()+45-210));
    int angle8 = -1 * ln8.angle();
    firebyunit8->setRotation(angle8);
    game->scene->addItem(firebyunit8);
}
