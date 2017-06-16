#include "Hphsiehphoto.h"
#include "Game.h"

extern Game * game;

Hphsiehphoto::Hphsiehphoto(QString str,QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    string=str;

    if(str==":images/shiehm.png"){
        ratio=70;       defence=3;     walkspeed=0.5;      attackarea=13;       mana=8;
    }
    else if(str==":images/hphsieh.png"){
        ratio=110;       defence=2;     walkspeed=0.87;      attackarea=10;     mana=3;
    }
    else if(str==":images/khliu.png"){
        ratio=80;       defence=2.6;     walkspeed=2;      attackarea=11;       mana=2;
    }
    else if(str==":images/wenson.png"){
        ratio=100;       defence=2.2;     walkspeed=0.6;      attackarea=18;     mana=5;
    }
    else if(str==":images/clee.png"){
        ratio=220;       defence=1;     walkspeed=1.8;      attackarea=9;     mana=6;
    }
    else if(str==":images/sisou.png"){
        ratio=120;       defence=1;     walkspeed=3;      attackarea=13;     mana=3;
    }
    else if(str==":images/hjsu.png"){
        ratio=130;       defence=1.5;     walkspeed=4;      attackarea=12;     mana=4;
    }
    else if(str==":images/chchen.png"){
        ratio=100;       defence=2;     walkspeed=2.5;      attackarea=21;     mana=4;
    }
    else if(str==":images/tsaic.png"){
        ratio=140;       defence=1;     walkspeed=1.5;      attackarea=16;     mana=12;
    }
    else if(str==":images/jsli.png"){
        ratio=80;       defence=1.5;     walkspeed=1.7;      attackarea=15;     mana=2;
    }


    QPixmap shiehm;
    shiehm.load(string);
    shiehm = shiehm.scaled(110,110,Qt::KeepAspectRatio);
    setPixmap(shiehm);
    //setPos(1620,220);
}

void Hphsiehphoto::mousePressEvent(QGraphicsSceneMouseEvent *event){

        if(game->ma->getmana()-1<0) return;
        game->ma->decrease(mana);
        int a=(rand()% 625)+25;
        un = new Myunit(ratio,string,defence,walkspeed,attackarea);
        QPixmap photo;
        photo.load(string);
        photo = photo.scaled(ratio,ratio,Qt::KeepAspectRatio);
        un->setPixmap(photo);
        game->scene->addItem(un);
        un->setPos(1330,a);
}
