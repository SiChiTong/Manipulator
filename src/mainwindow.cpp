#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QGraphicsView>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    // Set some basic properties.
    int width = 600;
    int height = 400;
    setFixedWidth(width);
    setFixedHeight(height);
    setWindowTitle("Manipulator");

    // Set the menu bar.
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = new QMenu("File", menuBar);
    QAction *exitAction = new QAction("Exit", fileMenu);
    setMenuBar(menuBar);
    
    // Set the status bar.
    QStatusBar *statusBar = new QStatusBar();
    setStatusBar(statusBar);

    scene = new QGraphicsScene(0, 0, 100, 100, this);
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    setCentralWidget(view);
    addText("Bonjour");
   /*
   QGraphicsScene
   scene->addText("Hello, world!");
   scene->addLine(QLineF(0,0, 100, 100));
   view->setScene(scene);
   setCentralWidget(view);*/

    /*scene.setSceneRect(0,0, 100, 100);
    scene.addRect(QRectF(0,0, 100, 100));
    scene.addLine(QLineF(0,0, 100, 100));
    scene.addLine(QLineF(0,100, 100, 0));

    QGraphicsView* view = new QGraphicsView(&scene);
    view->show();*/

        // etc...


}

MainWindow::~MainWindow()
{
}

void MainWindow::addText(char * text)
{
    scene->addText(text);
}
