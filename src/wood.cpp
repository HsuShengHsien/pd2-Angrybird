#include "wood.h"

Wood::Wood(float x, float y,float w,float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(w,h);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    //b2CircleShape bodyshape;
    //bodyshape.m_radius = sqrt(pow(w,2)+pow(h,2))/2;
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2.0f,h/2.0f);
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyBox;
    fixturedef.density = WOOD_DENSITY;
    fixturedef.friction = WOOD_FRICTION;
    fixturedef.restitution = WOOD_RESTITUTION;
   // g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);
    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

void Wood::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}
