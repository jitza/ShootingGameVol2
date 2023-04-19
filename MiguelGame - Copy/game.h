#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "player.h"
#include "score.h"
#include "health.h"
#include "weapons.h"

class Game : public QGraphicsView
{
    Q_OBJECT

public slots:
    void start();
    void restart();

public:
    Game(QWidget *parent = 0);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Weapons * weapon;
    int enemyCounter;
    int randomGenNum;
    void displayMainMenu();
    void gameOverMenu();

    ~Game();

};

#endif // MAINWINDOW_H
