#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(1020,654);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QPixmap(":/image/sky")));
    scene->setSceneRect(0,0,1020,654);
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground and boundary
    itemList.push_back(new Land(16,0.45,32,2.2,QPixmap(":/image/ground").scaled(width(),height()/6.0),world,scene));
    itemList.push_back(new Land(16,20,32,2.2,QPixmap("").scaled(width(),height()/6.0),world,scene));
    itemList.push_back(new Land(-2.2,20,2.2,32,QPixmap("").scaled(width(),height()),world,scene));
    itemList.push_back(new Land(33,20,2.2,32,QPixmap("").scaled(width()/6.0,height()),world,scene));

    // Create pig
    pig = new Pig(20.5f,6.0f,0.7f,&timer,QPixmap(":/image/King_pig.png").scaled(46,46),world,scene);
    pig->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(pig);
    inpig++;

    // Create barrier
    wood = new Wood(18.4f,6.0f,0.7f,2.8f,&timer,QPixmap(":/image/wood1").scaled(21,83),world,scene);
    wood->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(wood);

    wood2 = new Wood(22.4f,6.0f,0.7f,2.8f,&timer,QPixmap(":/image/wood1").scaled(21,83),world,scene);
    wood2->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(wood2);

    wood3 = new Wood(20.5f,8.0f,5.6f,0.6f,&timer,QPixmap(":/image/wood2").scaled(170,22),world,scene);
    wood3->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(wood3);
    //Create slingshot
    QGraphicsPixmapItem * sling= new QGraphicsPixmapItem();
    sling->setPixmap(QPixmap(":/image/slingshot"));
    sling->setPos(48,340);
    scene->addItem(sling);
    //Create bucket
    bucket= new QGraphicsPixmapItem();
    bucket->setPixmap(QPixmap(":/image/Bucket"));
    bucket->setPos(26,385);
    scene->addItem(bucket);
    //Create line
    upper_line = new QGraphicsLineItem();
    upper_line->setPen(QPen(Qt::black,8,Qt::SolidLine));
    upper_line->setLine(35,400,48,375);

    lower_line = new QGraphicsLineItem();
    lower_line->setPen(QPen(Qt::black,8,Qt::SolidLine));
    lower_line->setLine(35,400,85,375);

    scene->addItem(lower_line);
    scene->addItem(upper_line);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(&timer2,SIGNAL(timeout()),this,SLOT(killpig()));
    connect(&timer3,SIGNAL(timeout()),this,SLOT(debird()));

    timer.start(100/6);
    timer2.start(1000);
    timer3.start(15);

    Button *quitbutton = new Button();
    quitbutton->setPos(880,10);
    quitbutton->setPixmap(QPixmap(":/image/quitbtn"));
    connect(quitbutton,SIGNAL(clicked()),this,SLOT(quitslot()));
    scene->addItem(quitbutton);

    Button *rebutton = new Button();
    rebutton->setPos(820,12);
    rebutton->setPixmap(QPixmap(":/image/rebtn"));
    connect(rebutton,SIGNAL(clicked()),this,SLOT(reslot()));
    scene->addItem(rebutton);

}
bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    QMouseEvent *e = static_cast<QMouseEvent *>(event);
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {

        if(tmp==1 && ability<1){

               birdie->special();
               ability++;

                if(birdie->sp==1){

                     blackk=new Black(birdie->getpos().x,birdie->getpos().y,1.4f,&timer,QPixmap(":/image/Bblack").scaled(92,92),world,scene);
                     blackk->setLinearVelocity(b2Vec2(birdie->getLinearVelocity().x,birdie->getLinearVelocity().y));
                     itemList.push_back(blackk);
                     delete birdie;
                     insp=1;
                }
                if(birdie->sp==2){
                    blue2=new Blue(birdie->getpos().x,birdie->getpos().y,0.7f,&timer,QPixmap(":/image/blue").scaled(46,46),world,scene);
                    blue3=new Blue(birdie->getpos().x,birdie->getpos().y,0.7f,&timer,QPixmap(":/image/blue").scaled(46,46),world,scene);
                    blue2->setLinearVelocity(b2Vec2(birdie->getLinearVelocity().x,birdie->getLinearVelocity().y-1.1));
                    blue3->setLinearVelocity(b2Vec2(birdie->getLinearVelocity().x,birdie->getLinearVelocity().y+1.1));
                    insp=2;
                }

        }

        if(tmp==0){
        world->SetGravity(b2Vec2(0.0f, 0.0f));
        ability = 0;
       }
        if(count%4==0 /*&& count<4 */&& tmp==0){
        birdie = new Bird(4.5f,7.0f,0.7f,&timer,QPixmap(":/image/normal_bird").scaled(46,46),world,scene);

        // Setting the Velocity
        birdie->setLinearVelocity(b2Vec2(0,0));
        itemList.push_back(birdie);
        count++;
        return true;
       }
       if(count%4==1 /*&& count<4 */&&tmp==0){
        birdie = new Yellow(4.5f,7.0f,0.7f,&timer,QPixmap(":/image/yellow").scaled(46,46),world,scene);
        // Setting the Velocity
        birdie->setLinearVelocity(b2Vec2(0,0));
        itemList.push_back(birdie);
        count++;
        return true;
        }
        if(count%4==2 /*&& count<4 */&& tmp==0){
        birdie = new Black(4.5f,7.0f,0.7f,&timer,QPixmap(":/image/black").scaled(46,46),world,scene);
        // Setting the Velocity
        birdie->setLinearVelocity(b2Vec2(0,0));
        itemList.push_back(birdie);
        count++;
        return true;
        }
        if(count%4==3 /*&& count<4 */&&tmp==0){
         birdie = new Blue(4.5f,7.0f,0.7f,&timer,QPixmap(":/image/blue").scaled(46,46),world,scene);
         // Setting the Velocity
         birdie->setLinearVelocity(b2Vec2(0,0));
         itemList.push_back(birdie);
         count++;
         return true;
         }
     return true;
    }
    if(event->type() == QEvent::MouseMove)
    {

        return true;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {

        world->SetGravity(b2Vec2(0.0f, -9.8f));
        if(tmp==0){
             birdie->setLinearVelocity(b2Vec2(-(e->x()-148)/6,(e->y()-338)/6));
             tmp++;
        }
        return true;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::quitslot()
{
    close();
}

void MainWindow::reslot()
{
    count=0;
    tmp=0;
    insp=0;
    ability=0;
    delete birdie;
    delete wood;
    delete wood2;
    delete wood3;
    if(inpig == 1)
    {
        delete pig;
        pig = new Pig(20.5f,6.0f,0.7f,&timer,QPixmap(":/image/King_pig.png").scaled(46,46),world,scene);
        pig->setLinearVelocity(b2Vec2(0,0));

    }
    else if(inpig == 0)
    {
        pig = new Pig(20.5f,6.0f,0.7f,&timer,QPixmap(":/image/King_pig.png").scaled(46,46),world,scene);
        pig->setLinearVelocity(b2Vec2(0,0));
        inpig++;
        timer2.start(1000);
    }



    birdie = new Bird(4.5f,7.0f,0.7f,&timer,QPixmap(":/image/normal_bird").scaled(46,46),world,scene);
    birdie->setLinearVelocity(b2Vec2(0,0));

    wood = new Wood(18.4f,6.0f,0.7f,2.8f,&timer,QPixmap(":/image/wood1").scaled(21,83),world,scene);
    wood->setLinearVelocity(b2Vec2(0,0));


    wood2 = new Wood(22.4f,6.0f,0.7f,2.8f,&timer,QPixmap(":/image/wood1").scaled(21,83),world,scene);
    wood2->setLinearVelocity(b2Vec2(0,0));

    wood3 = new Wood(20.5f,8.0f,5.6f,0.6f,&timer,QPixmap(":/image/wood2").scaled(170,22),world,scene);
    wood3->setLinearVelocity(b2Vec2(0,0));

    count++;

}


void MainWindow::killpig()
{

    if(pig->getLinearVelocity().x>0.2 || pig->getLinearVelocity().x<(-0.2)){
        pig->hp--;

        if(pig->hp==0){
            delete pig;
            inpig--;
            timer2.stop();
        }
    }
}

void MainWindow::debird()
{

    if(tmp==1 && insp==0){
      if(birdie->getLinearVelocity()==b2Vec2(0,0)){
            delete birdie;
            tmp=0;
            return;
        }
     }

    if(tmp==1 && insp==1){
        if(blackk->getLinearVelocity()==b2Vec2(0,0)){
              delete blackk;
              insp=0;
              tmp=0;
              return;
          }
    }

    if(tmp==1 && insp==2){
        if(blue2->getLinearVelocity()==b2Vec2(0,0)&&blue3->getLinearVelocity()==b2Vec2(0,0)&&birdie->getLinearVelocity()==b2Vec2(0,0)){
            delete birdie;
            delete blue2;
            delete blue3;
            insp=0;
            tmp=0;
            return;
        }
    }
}

