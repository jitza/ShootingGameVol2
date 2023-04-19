#include "game.h"
#include "bullet.h"
#include "enemy.h"
#include "weapons.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

extern Game * game;

Bullet::Bullet()
{
    // build the rect
    //setRect(0,0,10,10); //setRect(0,0,10,50);
    // draw graphics
    //




    //if(game->weapon->randomWeapon > 0)

    // connect
    QTimer * timer = new QTimer();
    connect( timer, SIGNAL( timeout() ), this, SLOT( move() ) );
    timer->start(50);//emits timeout() signal every 50 milliseconds
    listCount =0;

}

Bullet::Bullet(int type)
{

    qDebug()<<"Change Nu,ber";
    // build the rect
    //setRect(0,0,10,10); //setRect(0,0,10,50);
    // draw graphics
    setPixmap(QPixmap(":/images/images/yellow.png"));

    // connect
    QTimer * timer = new QTimer();
    connect( timer, SIGNAL( timeout() ), this, SLOT( move() ) );
    timer->start(50);//emits timeout() signal every 50 milliseconds
    listCount =0;
}

void Bullet::move()
{


    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items_list = collidingItems();
    listCount = colliding_items_list.size();
    for(int i = 0; i < listCount; i++) {

        if( typeid(* (colliding_items_list[i]) ) == typeid(Enemy) ) {

            // increase the score
            game->score->increase();

            //remove them both
            scene()->removeItem( colliding_items_list[i] ); //remove current enemy
            scene()->removeItem(this);//remove the current bullet
    //release memory for removed bullet and enemy
            delete colliding_items_list[i];
            delete this;
            return;
        }
    }
    //end for
    // move bullet up
    setPos(x(),y()-10);
    if( (pos().y() + pixmap().height() )< 0 )
    { scene()->removeItem(this);
        delete this;
        qDebug()<<"Bullet deleted.";
    }
}

void Bullet::bulletType(int bulletType)
{

//    switch (bulletType)
//    {
//    case 1:
//        //this->setPixmap(QPixmap(":/images/bullet.png"));
//        qDebug()<<"Shouldn't be one";
//        break;
//    case 2:
//       //this->setPixmap(QPixmap(":/images/bee.png"));
//        qDebug()<<"Better";
//        break;
//    case 3:
//       //this->setPixmap(QPixmap(":/images/yellow.png"));
//        qDebug()<<"Even better Better";
//        break;

//    default:
//        qDebug()<<"never enter here";

//    }

}


void Bullet::nuclear()
{

}

void Bullet::atomicBullet()
{

}

void Bullet::shotgunBullet()
{


}
