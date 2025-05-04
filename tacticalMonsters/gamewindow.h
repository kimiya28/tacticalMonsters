#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "playinggamewindow.h"


namespace Ui {
class gameWindow;
}

class gameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = nullptr);
    ~gameWindow();

private slots:
    void on_startGameButton_clicked();

private:
    Ui::gameWindow *ui;
    playingGameWindow *playinggamewindow;
};

#endif // GAMEWINDOW_H
