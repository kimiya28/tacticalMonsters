#include "namewindow.h"
#include "ui_namewindow.h"

nameWindow::nameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::nameWindow)
{
    ui->setupUi(this);
}

nameWindow::~nameWindow()
{
    delete ui;
}
