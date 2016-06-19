#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QObject>

class Button :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //constructor
    Button();
    //mouse event
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void clicked();
};

#endif // BUTTON_H
