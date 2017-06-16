#include "Mana.h"
#include <QFont>
#include <QTimer>

Mana::Mana(QGraphicsItem *parent): QGraphicsTextItem(parent){

    mana = 7; //initialize mana to ten
    setPlainText(QString("Mana: ") + QString::number(mana));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",22));
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(increase()));
    timer->start(1200);
}

void Mana::decrease(int a){
    mana-=a;
    setPlainText(QString("Mana: ") + QString::number(mana));
}
void Mana::increase(){
    if(mana>=20) return;
    mana+=1;

    setPlainText(QString("Mana: ") + QString::number(mana));
}

int Mana::getmana(){
    return mana;
}

