#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <pig.h>
#include <button.h>
#include <wood.h>
#include <yellow.h>
#include <black.h>
#include <blue.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);

signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    void quitslot();
    void reslot();
    void killpig();
    void debird();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    QTimer timer2;
    QTimer timer3;
    Bird *birdie;
    Pig * pig;
    Bird *blackk;
    Bird *blue2;
    Bird *blue3;
    Wood * wood;
    Wood * wood2;
    Wood * wood3;
    b2Vec2 * velocity;
    int count=0;
    int tmp=0;
    int insp=0;
    int inpig=0;
    int ability=0;

    QGraphicsPixmapItem * bucket;
    QGraphicsLineItem * upper_line;
    QGraphicsLineItem * lower_line;
};

#endif // MAINWINDOW_H
