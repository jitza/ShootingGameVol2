#ifndef MENU_H
#define MENU_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Menu:public QObject, public QGraphicsRectItem {

    Q_OBJECT
  public:

      // constructors
      Menu(QString name, QGraphicsItem* parent=NULL);

      // public methods (events)
      void mousePressEvent(QGraphicsSceneMouseEvent *event);
      void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
      void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
  signals:
      void clicked();
  private:
      QGraphicsTextItem* text;
};

#endif // MENU_H
