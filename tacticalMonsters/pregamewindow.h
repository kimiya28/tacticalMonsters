#ifndef PREGAMEWINDOW_H
#define PREGAMEWINDOW_H

#include <QWidget>
#include "gamewindow.h"
#include "gallerywindow.h"

namespace Ui {
class preGameWindow;
}

class preGameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit preGameWindow(QWidget *parent = nullptr);
    ~preGameWindow();

private slots:
    void on_startButton_clicked();
    void on_galleryButton_clicked();

private:
    Ui::preGameWindow *ui;
    gameWindow *gamewindow;
    galleryWindow *gallerywindow;
};

#endif // PREGAMEWINDOW_H
