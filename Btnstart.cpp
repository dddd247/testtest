#include "Btnstart.h"
#include "Game.h"
#include <QPixmap>
extern Game * game;
Btnstart::Btnstart(){
    QPixmap start;
    start.load(":images/Start.jpg");
    start = start.scaled(200,200,Qt::KeepAspectRatio);
    setPixmap(start);
    setPos(1170,728);
}
void Btnstart::mousePressEvent(QGraphicsSceneMouseEvent *event){
    game->start();
}
