#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include<QList>

class Bullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
    Bullet(int type);
    void nuclear();
    void atomicBullet();
    void shotgunBullet();

public slots:
    void move();
    void bulletType(int);

private:
    int listCount;
};

#endif // BULLET_H
