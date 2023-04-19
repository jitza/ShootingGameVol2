#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy (QGraphicsItem * parent=0);
public slots:
    void move();

private:
    int movement;
    int visible;
};

#endif // ENEMY_H
