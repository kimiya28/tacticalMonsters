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
    void bfsSet(int startIndex, int index, int hexCount);
    void findNeighbors();
    void updateHexButton(int index);

private slots:

    void on_pl1_ag1_btn_clicked();

    void on_pl1_ag2_btn_clicked();

    void on_pl1_ag3_btn_clicked();

    void on_pl1_ag4_btn_clicked();

    void on_pl2_ag1_btn_clicked();

    void on_pl2_ag2_btn_clicked();

    void on_pl2_ag3_btn_clicked();

    void on_pl2_ag4_btn_clicked();

private:
    Ui::playingGameWindow *ui;
};

#endif // PLAYINGGAMEWINDOW_H
