#include "Selectcard.h"
#include "Btnmerge.h"
#include "Game.h"
#include <QList>
#include <QTimer>
extern Game * game;
Selectcard::Selectcard(QString str){

    string=str;
    ratio=110;
    QPixmap photo;
    photo.load(string);
    photo = photo.scaled(110,110,Qt::KeepAspectRatio);
    setPixmap(photo);

}

void Selectcard::mousePressEvent(QGraphicsSceneMouseEvent *event){

     if(game->readytomerge==false){
        this->setPos(x()+1400,y());
        if(game->selectorder<=3){
            game->selectedunit[game->selectorder] = string;
            game->selectorder+=1;
         }
        else return;
     }
     else{
         if(game->mergeorder<=1){
             this->setPos(800,350);
             game->unitselectedtomerge[game->mergeorder]=string;
             game->mergeorder++;
             QTimer * timer = new QTimer(this);
             connect(timer,SIGNAL(timeout()),this,SLOT(setratio()));
             timer->start(20);
         }
         else return;
     }
}

void Selectcard::setratio(){
    this->ratio-=1;
    QPixmap me;
    me.load(string);
    me = me.scaled(this->ratio,this->ratio,Qt::KeepAspectRatio);
    setPixmap(me);
    if(ratio<=5){
        if(game->mergeorder==2){
            game->merge();
            game->mergeorder=0;
            game->readytomerge=false;
        }
        delete this;
    }

}
