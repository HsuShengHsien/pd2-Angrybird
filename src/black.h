#ifndef BLACK_H
#define BLACK_H

#include "bird.h"

class Black:public Bird
{
public:
      Black(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
      virtual void special();
};

#endif // BLACK_H
