#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include<QObject>
#include <QMediaPlayer>

class Player : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    int getNumber();

public slots:
    void spawn();
    void spawnNewWeapon();
    void setNumber();
    void spawnNewBullet();
    void gotRandomWeapon(int);
    void resetToNormal();
 private:
    QMediaPlayer * bulletsound;
    int randomNumber;
    int weaponPrototype;
    QTimer * WeaponTimer;
    QTimer * LifeSpanWeaponTimer;
};

#endif // MYRECT_H
