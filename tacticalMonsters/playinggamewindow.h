#ifndef PLAYINGGAMEWINDOW_H
#define PLAYINGGAMEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QPolygonF>

namespace Ui {
class playingGameWindow;
}

class playingGameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit playingGameWindow(QWidget *parent = nullptr);
    ~playingGameWindow();
    QPolygonF createHexagon(QPointF center, double size);
    void openFile();
    void createHexButton(int index);
    void hexagonClicked(int index);

private slots:
    void on_pl1_ag1_clicked();

    void on_pl1_ag2_clicked();

private:
    Ui::playingGameWindow *ui;
};

#endif // PLAYINGGAMEWINDOW_H
