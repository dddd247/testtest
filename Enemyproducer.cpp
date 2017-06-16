#include "Enemyproducer.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
extern Game *game;
Enemyproducer::Enemyproducer(){
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(produceenemy()));
    timer->start(3000);
}

void Enemyproducer::produceenemy(){
    int a=(rand()% 625)+25;
    Enemy *en = new Enemy(100,":images/tsaimh.png",10,2);
    QPixmap photo;
    photo.load(":images/tsaimh.png");
    photo = photo.scaled(100,100,Qt::KeepAspectRatio);
    en->setPixmap(photo);
    en->setPos(250,a);
    game->scene->addItem(en);

}
