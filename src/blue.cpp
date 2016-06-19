#include "blue.h"

Blue::Blue(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}

void Blue::special()
{
   sp=2;
}
