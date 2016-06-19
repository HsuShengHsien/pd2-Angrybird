#ifndef YELLOW_H
#define YELLOW_H

#include "bird.h"

class Yellow:public Bird
{
public:
    Yellow(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void special();
};

#endif // YELLOW_H
