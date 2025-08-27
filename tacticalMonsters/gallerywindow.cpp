#include "gallerywindow.h"
#include "ui_gallerywindow.h"

galleryWindow::galleryWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::galleryWindow)
{
    ui->setupUi(this);
    ui->backButton1->setStyleSheet(
        "background: transparent; "
        "border: none; "
        "padding: 0; "
        "margin: 0;"
        );
    ui->backButton2->setStyleSheet(
        "background: transparent; "
        "border: none; "
        "padding: 0; "
        "margin: 0;"
        );
    ui->backButton3->setStyleSheet(
        "background: transparent; "
        "border: none; "
        "padding: 0; "
        "margin: 0;"
        );
    ui->backButton4->setStyleSheet(
        "background: transparent; "
        "border: none; "
        "padding: 0; "
        "margin: 0;"
        );

}

galleryWindow::~galleryWindow()
{
    delete ui;
}

void galleryWindow::on_backButton1_clicked()
{

    emit backToPreGameWindow();
    this->hide();
}


void galleryWindow::on_backButton2_clicked()
{
    emit backToPreGameWindow();
    this->hide();
}


void galleryWindow::on_backButton3_clicked()
{
    emit backToPreGameWindow();
    this->hide();
}


void galleryWindow::on_backButton4_clicked()
{
    emit backToPreGameWindow();
    this->hide();
}

