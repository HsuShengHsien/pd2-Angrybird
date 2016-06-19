#ifndef BLUE_H
#define BLUE_H

#include "bird.h"

class Blue:public Bird
{
public:
    Blue(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void special();
};

#endif // BLUE_H
