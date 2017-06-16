#include "Shiehmphoto.h"
#include "Game.h"

extern Game * game;

Shiehmphoto::Shiehmphoto(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QPixmap shiehm;
    shiehm.load(":images/shiehm.png");
    shiehm = shiehm.scaled(110,110,Qt::KeepAspectRatio);
    setPixmap(shiehm);
    setPos(1620,0);
}

void Shiehmphoto::mousePressEvent(QGraphicsSceneMouseEvent *event){

        if(game->ma->getmana()-5<0) return;
        game->ma->decrease(5);
        un = new Myunit(100,":images/shiehm.png",10,0.5,13);
        QPixmap photo;
        photo.load(":images/shiehm.png");
        photo = photo.scaled(100,100,Qt::KeepAspectRatio);
        un->setPixmap(photo);
        game->scene->addItem(un);
        un->setPos(850,400);
}
