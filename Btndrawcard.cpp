#include "Btndrawcard.h"
#include "Selectcard.h"
#include "Game.h"
#include <time.h>
#include <stdlib.h>
#include <QPixmap>

extern Game * game;

Btndrawcard::Btndrawcard(){

    QPixmap drawcard;
    drawcard.load(":images/drawcard.png");
    drawcard = drawcard.scaled(200,200,Qt::KeepAspectRatio);
    setPos(1370,612);
    setPixmap(drawcard);
    position=330;
    order=0;

}
void Btndrawcard::mousePressEvent(QGraphicsSceneMouseEvent *event){

    int seed = (unsigned)time(NULL);
    srand(seed);
    int a=(rand() % 3);
    if(a==0){
        Selectcard *card = new Selectcard(":images/sisou.png");
        card->setPos(50,position);
        game->scene->addItem(card);
        position+=110;
        order++;
    }
    if(a==1){
        Selectcard *card1 = new Selectcard(":images/hjsu.png");
        card1->setPos(50,position);
        game->scene->addItem(card1);
        position+=110;
        order++;
    }
    if(a==2){
        Selectcard *card2 = new Selectcard(":images/chchen.png");
        card2->setPos(50,position);
        game->scene->addItem(card2);
        position+=110;
        order++;
    }
    if(order==2) delete this;
}
