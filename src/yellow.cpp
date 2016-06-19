#include "yellow.h"

Yellow::Yellow(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}

void Yellow::special()
{
    setLinearVelocity(b2Vec2(getLinearVelocity().x*2.5,getLinearVelocity().y*2.5));
}
