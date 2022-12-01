#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->addLine(0,0,50,50);
    GameOfLife game = FileParser::readfile("input.txt");

}

MainWindow::~MainWindow()
{
    delete ui;
}

