#include "gallerywindow.h"
#include "ui_gallerywindow.h"

galleryWindow::galleryWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::galleryWindow)
{
    ui->setupUi(this);
}

galleryWindow::~galleryWindow()
{
    delete ui;
}
