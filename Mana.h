#ifndef MANA_H
#define MANA_H

#include <QGraphicsTextItem>
#include <QObject>

class Mana: public QGraphicsTextItem{
    Q_OBJECT
public:
    Mana(QGraphicsItem * parent=0);
    int getmana();

public slots:
    void decrease(int a);
    void increase();
private:
    int mana;

};

#endif // MANA_H
