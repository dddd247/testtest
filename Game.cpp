#include "Game.h"
#include <QGraphicsScene>
#include <QString>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <stdlib.h>
#include "Selectcard.h"
#include "Enemyproducer.h"
#include <time.h>
#include <stdlib.h>
#include "button.h"
Game::Game(): QGraphicsView(){

    screenMode=0;
    selectorder=0;
    mergeorder=0;
    mergeposition=330;
    readytomerge=false;
    unitselectedtomerge[0]="null";
    unitselectedtomerge[1]="null";
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1700,800);
    setScene(scene);
    setFixedSize(1700,800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //btn_start = new Btnstart();
    //scene->addItem(btn_start);

    btn_managecard = new Btnmanagecard();
    scene->addItem(btn_managecard);

    QPixmap page;
    page.load(":images/beginpage.jpg");
    page = page.scaled(1700,750,Qt::KeepAspectRatioByExpanding);
    scene->setBackgroundBrush(page);     
}

void Game::start(){

    scene->removeItem(btn_start);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1800,800);
    setScene(scene);

    ma = new Mana;
    ma->setPos(800,10);
    scene->addItem(ma);

    t1 = new Tower();
    t1->setPos(120,50);
    scene->addItem(t1);
    t2 = new Tower();
    t2->setPos(90,350);
    scene->addItem(t2);
    h2= new Health();
    h2->setPos(90,318);
    scene->addItem(h2);
    t3 = new Tower();
    t3->setPos(120,650);
    scene->addItem(t3);

    b1 = new Base();
    b1->setPos(1400,50);
    scene->addItem(b1);
    b2 = new Base();
    b2->setPos(1430,350);
    scene->addItem(b2);
    b3 = new Base();
    b3->setPos(1400,650);
    scene->addItem(b3);
    h1= new Health();
    h1->setPos(1430,318);
    scene->addItem(h1);


    Hphsiehphoto *p1 = new Hphsiehphoto(selectedunit[0]);
    p1->setPos(1620,0);
    scene-> addItem(p1);
    Hphsiehphoto *p2 = new Hphsiehphoto(selectedunit[1]);
    p2->setPos(1620,110);
    scene-> addItem(p2);
    Hphsiehphoto *p3 = new Hphsiehphoto(selectedunit[2]);
    p3->setPos(1620,220);
    scene-> addItem(p3);
    Hphsiehphoto *p4 = new Hphsiehphoto(selectedunit[3]);
    p4->setPos(1620,330);
    scene-> addItem(p4);

    Enemyproducer *enemyproducer = new Enemyproducer();

    Hero *hero = new Hero();
    QPixmap he;
    he.load(":images/shiehm.png");
    he = he.scaled(110,110,Qt::KeepAspectRatio);
    hero->setPixmap(he);
    hero->setPos(1000,300);
    scene->addItem(hero);
}
void Game::managecard(){

    scene->removeItem(btn_managecard);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1800,800);
    setScene(scene);
    QPixmap bg;
    bg.load(":images/green.jpg");
    bg = bg.scaled(2000,2000,Qt::KeepAspectRatio);
    scene->setBackgroundBrush(bg);

    btn_start = new Btnstart();
    scene->addItem(btn_start);
    btn_drawcard = new Btndrawcard();
    scene->addItem(btn_drawcard);
    btn_merge = new Btnmerge();
    scene->addItem(btn_merge);


    Selectcard *c1 = new Selectcard(":images/shiehm.png");
    c1->setPos(50,0);
    scene->addItem(c1);
    Selectcard *c2 = new Selectcard(":images/hphsieh.png");
    c2->setPos(50,110);
    scene->addItem(c2);
    Selectcard *c3 = new Selectcard(":images/wenson.png");
    c3->setPos(50,220);
    scene->addItem(c3);
    Selectcard *c4 = new Selectcard(":images/khliu.png");
    c4->setPos(130,0);
    scene->addItem(c4);
    Selectcard *c5 = new Selectcard(":images/clee.png");
    c5->setPos(130,110);
    scene->addItem(c5);

}
void Game::decidewinorlose(){
    
    QPixmap wl;
    QString messege;
    if(h2->getHealth()<=0){
        wl.load(":images/win.jpg");
        messege = "you win!";
    }
    else{
        wl.load(":images/lose.jpg");
        messege = "no~~~~~";
    }

    displayGameOverWindow(messege);
    wl = wl.scaled(250,250,Qt::KeepAspectRatioByExpanding);
    scene->setBackgroundBrush(wl);
}
void Game::merge(){
    if(unitselectedtomerge[0]!="null"&&unitselectedtomerge[1]!="null"){
        int seed = (unsigned)time(NULL);
        srand(seed);
        int a=(rand() % 2);
        if(a==1){
            Selectcard *c6 = new Selectcard(":images/tsaic.png");
            c6->setPos(130,mergeposition);
            scene->addItem(c6);
            mergeposition+=110;
        }
        else{
            Selectcard *c6 = new Selectcard(":images/jsli.png");
            c6->setPos(130,mergeposition);
            scene->addItem(c6);
            mergeposition+=110;

        }
    }
}

void Game::displayGameOverWindow(QString textToDisplay)
{
    //disable all scene items
    for (size_t i=0, n = scene->items().size();i<n;i++){
        scene->items()[i]->setEnabled(false);
    }

    //pop up semi transparent panel
    drawPanel(0,0,1750,800,Qt::black,0.4);

    //draw panel
    drawPanel(650,184,400,400,Qt::lightGray,0.75);

    //create playAgain button
    Button* playAgain = new Button(QString("play again"));
    playAgain->setPos(750,300);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    //create quit button
    Button* quit = new Button(QString("quit"));
    quit->setPos(750,375);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));


     // create text
    QGraphicsTextItem* overText = new QGraphicsTextItem(textToDisplay);
    overText->setPos(750,255);
    scene->addItem(overText);

}

void Game::restartGame()
{

    scene->clear();
    start();
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

