#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "QMessageBox"
#include "playerClass.h"
#include "QDebug"
#include "iostream"
#include "string"

using namespace std;



gameWindow::gameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gameWindow)
    , playinggamewindow(nullptr)
{
    ui->setupUi(this);
}

gameWindow::~gameWindow()
{
    delete ui;
}



void gameWindow::on_startGameButton_clicked(){
    if(ui->player1Name->toPlainText().isEmpty() || ui->player2Name->toPlainText().isEmpty())
        ui->label_3->setText("PLAYER NAME IS EMPTY!");
    else {
            Player player1(ui->player1Name->toPlainText().toStdString());
            Player player2(ui->player2Name->toPlainText().toStdString());


            if(!playinggamewindow)
                playinggamewindow = new playingGameWindow;
            playinggamewindow->show();
            playinggamewindow->openFile();
            this->hide();
        }

}
