#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 1201, 871)),
    timer(new QTimer)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    item = new QGraphicsPixmapItem(QPixmap(":/res/reimu.jpg"));
    scene->addItem(item);
    item->setPos(200, 200);
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        item->setPos(item->x(), item->y() - 10);
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        item->setPos(item->x(), item->y() + 10);
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        item->setPos(item->x() - 10, item->y());
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        item->setPos(item->x() + 10, item->y());
        break;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    bullet *b = new bullet;

    if(qrand() % 2 == 0) {
        b->setPixmap(QPixmap(":/res/black_bullet.png").scaled(50, 50));
    }
    else {
        b->setPixmap(QPixmap(":/res/red_bullet.png").scaled(50, 50));
    }
    b->setPos(item->x() + item->pixmap().width() / 2 - b->pixmap().width() / 2, item->y() - b->pixmap().height());
    b->connect(timer, SIGNAL(timeout()), b, SLOT(fly()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
}


































