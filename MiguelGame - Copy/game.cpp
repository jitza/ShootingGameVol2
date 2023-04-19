#include "game.h"
#include "menu.h"
#include <QTimer>
#include <QMediaPlayer>



Game::Game(QWidget *parent)
    : QGraphicsView (parent)
{
    randomGenNum = 0;
    enemyCounter = 0;
    // create the scene by initializing our scene data member
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/images/bg.jpg")));

    // visualize the newly initialized scene
    setScene(scene); // since class Game inherits from class QGraphicsView, it can directly visualize a scene
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->pixmap(); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); //generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->removeItem(player);

    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setAudioOutput(new QAudioOutput());
    music->setSource(QUrl("qrc:/sounds/sounds/bgsound.mp3"));
    music->play();

    displayMainMenu();

    // show the
    show();
}

void Game::displayMainMenu()
{
    // create the title text
      QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Space War"));
      QFont titleFont("comic sans",50);
      titleText->setFont(titleFont);
      int txPos = this->width()/2 - titleText->boundingRect().width()/2;
      int tyPos = 150;
      titleText->setPos(txPos,tyPos);
      scene->addItem(titleText);

      // create the play button
      Menu * playButton = new Menu(QString("Play"));
      int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
      int byPos = 275;
      playButton->setPos(bxPos,byPos);
      connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
      scene->addItem(playButton);

      // create the Restart button
      Menu * restartButton = new Menu(QString("Restart"));
      int rxPos = this->width()/2 - playButton->boundingRect().width()/2;
      int ryPos = 275;
      restartButton->setPos(bxPos,byPos);
      connect(restartButton,SIGNAL(clicked()),this,SLOT(restart()));
      scene->addItem(restartButton);

      scene->removeItem(restartButton);

      // create the quit button
      Menu* quitButton = new Menu(QString("Quit"));
      int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
      int qyPos = 350;
      quitButton->setPos(qxPos,qyPos);
      connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
      scene->addItem(quitButton);
}

void Game::gameOverMenu()
{
    //Remome Health
       scene->removeItem(health);

       // create the title text
       QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Space War"));
       QFont titleFont("comic sans",50);

       titleText->setFont(titleFont);
       int txPos = this->width()/2 - titleText->boundingRect().width()/2;
       int tyPos = 150;
       titleText->setPos(txPos,tyPos);
       scene->addItem(titleText);

       // create the Restart button
       Menu * restartButton = new Menu(QString("Play Again"));
       int rxPos = this->width()/2 - restartButton->boundingRect().width()/2;
       int ryPos = 275;
       restartButton->setPos(rxPos,ryPos);
       connect(restartButton,SIGNAL(clicked()),this,SLOT(restart()));
       scene->addItem(restartButton);

       // create the quit button
       Menu* quitButton = new Menu(QString("Quit"));
       int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
       int qyPos = 350;
       quitButton->setPos(qxPos,qyPos);
       connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
       scene->addItem(quitButton);

       player->clearFocus();
}


void Game::start()
{

    // create the scene by initializing our scene data member
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/images/bg.jpg")));

    // visualize the newly initialized scene
    setScene(scene); // since class Game inherits from class QGraphicsView, it can directly visualize a scene
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->pixmap(); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500); //generalize to always be in the middle bottom of screen

    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add the player to the scene
    scene->addItem(player);

    // create the score
    score = new Score();
    scene->addItem(score);
    health = new Health();

    health->setPos(health->x(),health->y()+25);

    if(health == 0){
        displayMainMenu();
    }

    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);


    //Generate Random Number
    QTimer * randomTimer = new QTimer();
    QObject::connect(randomTimer,SIGNAL(timeout()),player,SLOT(setNumber()));
    randomTimer->start(8000);

//    player->setNumber();

    player->setNumber();

    //Span weapons
    QTimer * WeaponTimer = new QTimer();
    QObject::connect(WeaponTimer,SIGNAL(timeout()),player,SLOT(spawnNewWeapon()));
    WeaponTimer->start(12000);

    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setAudioOutput(new QAudioOutput());
    music->setSource(QUrl("qrc:/sounds/sounds/bgsound.mp3"));
    music->play();

    // show the
     show();
}

void Game::restart()
{
    scene->clear();
    start();
}

Game::~Game()
{

}
