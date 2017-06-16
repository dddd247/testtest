#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    health = 200;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",18));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}
void Health::increase(){
    health++;
    setPlainText(QString("Health: ") + QString::number(health));
}
int Health::getHealth(){
    return health;
}
