#include "weapons.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include<QDebug>
#include<stdlib.h>
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

extern Game * game;
using std::srand;
using std::rand;
Weapons::Weapons(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //draw Enemy rect the same size as our player rect
    //700 ensures enemies are created within our screen’s 800 width because the rand num will be a value
    //in the range of 0 and 699. However, we must take into account that the width of the enemy is 100

    connect(this,SIGNAL(getweaponType(int)),game->player,SLOT(gotRandomWeapon(int)));
    srand (time(0));
    randomWeapon = 0;
    listCount =0;
    int random_x = rand() % 700;
    random_weapon =0;

    random_weapon = rand() % 30;
    random_weapon = random_weapon % 3;
    random_weapon++;

    setweaponType(random_weapon);
    setPos(random_x, 0);

    //draw the rect/image
    setPixmap(QPixmap(":/images/images/box.png"));
    QTimer * timer = new QTimer(this);
    //connect
    connect(timer, SIGNAL(timeout()), this, SLOT(move() ) );
    timer->start(50);//repeat countdown clock to emit timeout() signal every 50 milliseconds

}

int Weapons::getType()
{
    return weaponType;
}

void Weapons::atomicBomb(int x, int y)
{
    qDebug()<<x<<y;
    Bullet *bullet = new Bullet(); //print to the console to show that we have entered this block and that a Bullet was created
    bullet->setPixmap(QPixmap(":/images/images/bomb.png"));
    //Life Span of weapons



    bullet->setPos(x,y); //uses the x and y coordinates our rectangle
    game->scene->addItem(bullet); //get the scene that the current object belongs to and add the newly created bullet

    qDebug()<<"bullet created.";


        QList<QGraphicsItem*> L = game->scene->items();
        int listCount = L.size();
        for(int i = 0; i < listCount; i++) {

            if( typeid(* (L[i]) ) == typeid(Enemy) ) {

                // increase the score
                game->score->increase();

                //remove them both
                game->scene->removeItem( L[i] ); //remove current enemy
                //release memory for removed bullet and enemy
                delete L[i];

            }
        }
}

void Weapons::multipleShot(int x, int y)
{
    qDebug()<<x<<y;
    //create a new Bullet object
    Bullet *bullet = new Bullet(); //print to the console to show that we have entered this block and that a Bullet was created
    bullet->setPixmap(QPixmap(":/images/images/bee.png"));

    qDebug()<<"bullet created.";

    bullet->setPos(x,y); //uses the x and y coordinates our rectangle
    game->scene->addItem(bullet); //get the scene that the current object belongs to and add the newly created bullet


    //create a new Bullet object
    Bullet *bullet2 = new Bullet(); //print to the console to show that we have entered this block and that a Bullet was created
    bullet2->setPixmap(QPixmap(":/images/images/bee.png"));

    qDebug()<<"bullet created.";
    bullet2->setPos(x+100 ,y); //uses the x and y coordinates our rectangle
    game->scene->addItem(bullet2); //get the scene that the current object belongs to and add the newly created bullet



    //create a new Bullet object
    Bullet *bullet3 = new Bullet(); //print to the console to show that we have entered this block and that a Bullet was created
    bullet3->setPixmap(QPixmap(":/images/images/bee.png"));

    qDebug()<<"bullet created.";
    bullet3->setPos(x-100 ,y); //uses the x and y coordinates our rectangle
    game->scene->addItem(bullet3); //get the scene that the current object belongs to and add the newly created bullet


    //create a new Bullet object
    Bullet *bullet4 = new Bullet(); //print to the console to show that we have entered this block and that a Bullet was created
    bullet4->setPixmap(QPixmap(":/images/images/bee.png"));

    qDebug()<<"bullet created.";
    bullet4->setPos(x+50 ,y); //uses the x and y coordinates our rectangle
    game->scene->addItem(bullet4); //get the scene that the current object belongs to and add the newly created bullet

    //create a new Bullet object
    Bullet *bullet5 = new Bullet(); //print to the console to show that we have entered this block and that a Bullet was created
    bullet5->setPixmap(QPixmap(":/images/images/bee.png"));

    qDebug()<<"bullet created.";
    bullet5->setPos(x-50 ,y); //uses the x and y coordinates our rectangle
    game->scene->addItem(bullet5); //get the scene that the current object belongs to and add the newly created bullet
}

void Weapons::shotgunShots(int x, int y)
{
    qDebug()<<x<<y;
    //create a new Bullet object
    Bullet *bullet = new Bullet(); //print to the console to show that we have entered this block and that a Bullet was created
    bullet->setPixmap(QPixmap(":/images/images/yellow.png"));

    qDebug()<<"bullet created.";
    bullet->setPos(x,y); //uses the x and y coordinates our rectangle
    game->scene->addItem(bullet); //get the scene that the current object belongs to and add the newly created bullet




    //create a new Bullet object
    Bullet *bullet2 = new Bullet(); //print to the console to show that we have entered this block and that a Bullet was created
    bullet2->setPixmap(QPixmap(":/images/images/purple.png"));

    qDebug()<<"bullet created.";
    bullet2->setPos(x+100 ,y+10); //uses the x and y coordinates our rectangle
    game->scene->addItem(bullet2); //get the scene that the current object belongs to and add the newly created bullet



    //create a new Bullet object
    Bullet *bullet3 = new Bullet(); //print to the console to show that we have entered this block and that a Bullet was created
    bullet3->setPixmap(QPixmap(":/images/images/red.png"));

    qDebug()<<"bullet created.";
    bullet3->setPos(x+60 ,y+50); //uses the x and y coordinates our rectangle
    game->scene->addItem(bullet3); //get the scene that the current object belongs to and add the newly created bullet


    //create a new Bullet object
    Bullet *bullet4 = new Bullet(); //print to the console to show that we have entered this block and that a Bullet was created
    bullet4->setPixmap(QPixmap(":/images/images/orange.png"));

    qDebug()<<"bullet created.";
    bullet4->setPos(x+50 ,y-50); //uses the x and y coordinates our rectangle
    game->scene->addItem(bullet4); //get the scene that the current object belongs to and add the newly created bullet
}

void Weapons::move()
{


    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items_list = collidingItems();
    listCount = colliding_items_list.size();
    for(int i = 0; i < listCount; i++) {

        if( typeid(* (colliding_items_list[i]) ) == typeid(Player) )
        {

            // increase the score
            qDebug()<<"weapon got";

            qDebug()<<weaponType;
            emit getweaponType(weaponType);
            //game->weapon->randomWeapon = weaponType;
            //remove them bothd
            scene()->removeItem(this);//remove the current bullet
            //release memory for removed bullet and enemy
            delete this;
            return;

        }
    }
    //end for


    setPos( x(), y() + 5);
    //enemy is moving down so we increase the y value. We increase by 5 to be slower than bullet
    if( pos().y() > 600 )
    {
        //decrease the health
        scene()->removeItem(this);
        delete this;
        qDebug()<<"”Enemy weapon.”";
    }
}

void Weapons::setweaponType(int type)
{
    if(game->randomGenNum == type)
    {
        srand(time(0));
        type = rand() % 3;
         ++type;
    }

    weaponType = type;
    game->randomGenNum = type;
    qDebug()<<"here "<<weaponType<<" here";

}




