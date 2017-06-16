#ifndef ENEMYPRODUCER_H
#define ENEMYPRODUCER_H
#include <QObject>

class Enemyproducer: public QObject{
    Q_OBJECT
public:
    Enemyproducer();
public slots:
    void produceenemy();
};

#endif // ENEMYPRODUCER_H
