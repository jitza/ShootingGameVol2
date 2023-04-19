#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "weapons.h"
#include "game.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <ctime>
#include <QGraphicsItem>
#include <future>

Weapons *randomWeapon;
extern Game *game;


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    bulletsound = new QMediaPlayer();
    bulletsound->setAudioOutput(new QAudioOutput());
    bulletsound->setSource(QUrl("qrc:/sounds/sounds/bullet.mp3"));
    randomNumber = 0;
    setPixmap( QPixmap(":/images/images/player.png") );
    weaponPrototype =0;
    //Weapons *Weapon = new Weapons;

    //

}

void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<"Myrect knows that you pressed a key"<<event->key();
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
    {
        if( pos().x() > 0 )
            setPos( x() - 18, y() );
    }
    else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
    {
        if( pos().x() + 100 < 800 )
            setPos(x() + 18, y());
    }


    else if(event->key() == Qt::Key_Space)
    {

        qDebug()<<weaponPrototype<<" HERE<-";
        switch (weaponPrototype)
        {
        case 3:
        {
            int x;
            int y;
            x = pos().x();
            y = pos().y();

            qDebug()<<"got 3333";
                game->weapon->shotgunShots(x,y);

            //Life Span of weapons
             QTimer::singleShot(3000, this, SLOT(resetToNormal()));

        }
            break;
        case 2:
        {
            int x;
            int y;
            x = pos().x();
            y = pos().y();
            game->weapon->multipleShot(x,y);
            qDebug()<<"got 222";

            //Life Span of weapons
            QTimer::singleShot(3000, this, SLOT(resetToNormal()));
            //  delete LifeSpanWeaponTimer;

        }
            break;


        case 1:
        {
            int x;
            int y;
            x = pos().x();
            y = pos().y();


            game->weapon->atomicBomb(x,y);
            QTimer::singleShot(3000, this, SLOT(resetToNormal()));

            // delete LifeSpanWeaponTimer;
        }

            break;
        case 0:
        {
            //create a new Bullet object
            Bullet *bullet = new Bullet(); //print to the console to show that we have entered this block and that a Bullet was created


            qDebug()<<"bullet created.";
            bullet->setPos(x(),y()); //uses the x and y coordinates our rectangle
            bullet->setPixmap(QPixmap(":/images/images/bullet.png"));
            scene()->addItem(bullet); //get the scene that the current object belongs to and add the newly created bullet
        }
            break;
        default:
            //create a new Bullet object
            qDebug()<<"NEVER ENTER HERE";
        }



        // play bulletsound
        if (bulletsound->playbackState() == QMediaPlayer::PlayingState) {
            bulletsound->setPosition(0);
        } else if (bulletsound->playbackState() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }
        //scene->addItem();
    }

}


void Player::spawn()
{
    //create a new Enemy
    Enemy *enemy = new Enemy();
    //add newly created enemy to the same scene as the player
    scene()->addItem(enemy);
}


void Player::spawnNewWeapon()
{
    //    qDebug()<< "Start\n";
    //    auto start = std::chrono::high_resolution_clock::now();
    //    for(int i=0;i<10;++i)
    //    {
    //        qDebug() << (10-i) << '\n';
    //        std::this_thread::sleep_until(start + (i+1)*std::chrono::seconds(1));
    //    }
    //    qDebug() << "DONE\n";
    srand(time(0));


    int random = rand() % 10000;
    int i =0;
    while (i < 1) {


        WeaponTimer = new QTimer();
        QObject::connect(WeaponTimer,SIGNAL(timeout()),this,SLOT(spawnNewBullet()));
        WeaponTimer->start(random);
        i++;
    }
    qDebug()<<"oout";


}


int Player::getNumber()
{
    qDebug()<<randomNumber;
    return randomNumber;
}

void Player::setNumber()
{
    srand (time(NULL));
    qDebug()<<randomNumber<<" here";
    randomNumber = rand() % 5000;

}

void Player::spawnNewBullet()
{
    WeaponTimer->stop();
    delete WeaponTimer;
    //create a new Enemy
    randomWeapon = new Weapons();

    //add newly created enemy to the same scene as the player
    scene()->addItem(randomWeapon);
    //connect(randomWeapon,SIGNAL(getweaponType(int)),this,SLOT(gotRandomWeapon(int)));
}

void Player::gotRandomWeapon(int randomWeapon)
{

    weaponPrototype = randomWeapon;

}

void Player::resetToNormal()
{

    weaponPrototype = 0;
    //LifeSpanWeaponTimer->killTimer(1);




}
