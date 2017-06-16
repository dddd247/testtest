#include "Btnmerge.h"
#include "Game.h"
#include <time.h>
#include <stdlib.h>
#include <QPixmap>

extern Game * game;

Btnmerge::Btnmerge(){

    QPixmap drawcard;
    drawcard.load(":images/merge.png");
    drawcard = drawcard.scaled(200,200,Qt::KeepAspectRatio);
    setPos(1505,612);
    setPixmap(drawcard);

}

void Btnmerge::mousePressEvent(QGraphicsSceneMouseEvent *event){
    game->readytomerge=true;

}
