#ifndef GAME_H
#define GAME_H
#include "Hphsiehphoto.h"
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QTimer>
#include "Tower.h"
#include "Base.h"
#include "Enemy.h"
#include "Hero.h"
#include "Mana.h"
#include "Health.h"
#include "Btnstart.h"
#include "Btnmanagecard.h"
#include "Btndrawcard.h"
#include "Btnmerge.h"

class Game: public QGraphicsView{

public:

    Game();
    void start();
    void managecard();
    void decidewinorlose();
    void merge();
    QGraphicsScene * scene;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void displayGameOverWindow(QString textToDisplay);

    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    Btnstart *btn_start;
    Btnmanagecard *btn_managecard;
    Btndrawcard *btn_drawcard;
    Btnmerge *btn_merge;
    Mana *ma;
    Health *h1;
    Health *h2;
    Tower *t1;
    Tower *t2;
    Tower *t3;
    Base *b1;
    Base *b2;
    Base *b3;
    QString selectedunit[4];
    QString unitselectedtomerge[2];
    int mergeorder;
    int mergeposition;
    int selectorder;
    int screenMode;
    bool readytomerge;

public slots:
    void restartGame();


};



#endif // GAME_H
