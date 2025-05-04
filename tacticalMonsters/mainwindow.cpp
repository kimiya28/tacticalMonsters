#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    pregamewindow(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pregamewindow;
}

void MainWindow::on_playButton_clicked(){
    if(!pregamewindow){
        pregamewindow = new preGameWindow;
    }
    pregamewindow->show();
    this->hide();
}
