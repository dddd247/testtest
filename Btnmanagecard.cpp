#include "Btnmanagecard.h"
#include "Game.h"
#include <QPixmap>
extern Game * game;
Btnmanagecard::Btnmanagecard(){
    QPixmap manage;
    manage.load(":images/managecard.jpg");
    manage = manage.scaled(125,125,Qt::KeepAspectRatio);
    setPixmap(manage);
    setPos(780,600);
}
void Btnmanagecard::mousePressEvent(QGraphicsSceneMouseEvent *event){
    game->managecard();
}
