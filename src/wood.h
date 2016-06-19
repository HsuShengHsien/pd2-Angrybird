#ifndef WOOD_H
#define WOOD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define WOOD_DENSITY 10.0f
#define WOOD_FRICTION 0.3f
#define WOOD_RESTITUTION 0.5f

class Wood:public GameItem
{
public:
    Wood(float x, float y, float w,float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
};

#endif // WOOD_H
