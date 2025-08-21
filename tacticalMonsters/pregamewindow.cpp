 #include "pregamewindow.h"
#include "ui_pregamewindow.h"

preGameWindow::preGameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::preGameWindow),
    gamewindow(nullptr),
    gallerywindow(nullptr)

{
    ui->setupUi(this);
}

preGameWindow::~preGameWindow()
{
    delete ui;
}

void preGameWindow::on_startButton_clicked()
{
    if(!gamewindow){
        gamewindow = new gameWindow;
    }
    gamewindow->show();
    this->hide();
}

void preGameWindow::on_galleryButton_clicked()
{
    if(!gallerywindow){
        gallerywindow = new galleryWindow;
    }
    gallerywindow->show();
    this->hide();
}

