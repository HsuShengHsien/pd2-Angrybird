#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>
#include <pig.h>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class Bird : public GameItem
{
public:
    Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
    b2Vec2 getLinearVelocity();
    b2Vec2 getpos();

    virtual void special();
    int sp=0;
private:
    b2Vec2 x;
    b2Vec2 p;
signals:
    void clicked();
};

#endif // BIRD_H
