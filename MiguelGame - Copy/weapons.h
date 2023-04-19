#ifndef WEAPONS_H
#define WEAPONS_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Weapons: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Weapons(QGraphicsItem * parent=0);
    void setWeapontType(int);
    int getType();
    int randomWeapon;
    void atomicBomb(int x, int y);
    void multipleShot(int x, int y);
    void shotgunShots(int x, int y);


signals:
    void getweaponType(int);

public slots:
    void move();


private:
    void setweaponType(int);
    int listCount;
    int weaponType;
    int random_weapon;

};



#endif // WEAPONS_H
