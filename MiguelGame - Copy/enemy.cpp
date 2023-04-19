#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include<QDebug>
#include<stdlib.h>
#include "game.h"

extern Game * game;
using std::srand;
using std::rand;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{ //draw Enemy rect the same size as our player rect
    //700 ensures enemies are created within our screen’s 800 width because the rand num will be a value
    //in the range of 0 and 699. However, we must take into account that the width of the enemy is 100
    int random_x = rand() % 700;
    setPos(random_x, 0);

    //draw the rect/image
    setPixmap(QPixmap(":/images/images/enemy.png"));
    QTimer * timer = new QTimer(this);
    movement = 4;
    game->enemyCounter++;
    //connect
    //connect(timer, SIGNAL(timeout()), this, SLOT(move() ) );

    connect(timer, SIGNAL(timeout()), this, SLOT(move() ) );
    timer->start(50);//repeat countdown clock to emit timeout() signal every 50 milliseconds
}
void Enemy::move()
{
    //Bonus:Enemy Become invisible for couple of secs
    if (visible == 30)
            visible = 0;

        if (game->score->getScore() >=45 && visible > 10)
            setPixmap(QPixmap(":/images/images/enemyInvis.png"));
        else
            setPixmap(QPixmap(":/images/images/enemy.png"));

        visible++;

        if (game->score->getScore() >14)
            movement = 8;


    setPos( x(), y() + movement);
    //enemy is moving down so we increase the y value. We increase by 5 to be slower than bullet
    if( pos().y() > 600 )
    {
      //decrease the health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug()<<"”Enemy deleted.”";

        if (game->health->getHealth() == 0){

            qDebug()<<"game Over";
            game->gameOverMenu();
        }

    }
}
