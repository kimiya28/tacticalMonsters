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

    void on_pl1_ag5_btn_clicked();

    void on_pl1_ag6_btn_clicked();

    void on_pl1_ag7_btn_clicked();

    void on_pl1_ag8_btn_clicked();

    void on_pl1_ag9_btn_clicked();

    void on_pl1_ag10_btn_clicked();

    void on_pl1_ag11_btn_clicked();

    void on_pl1_ag12_btn_clicked();

    void on_pl1_ag13_btn_clicked();

    void on_pl1_ag14_btn_clicked();

    void on_pl1_ag15_btn_clicked();

    void on_pl1_ag16_btn_clicked();

    void on_pl1_ag17_btn_clicked();

    void on_pl1_ag18_btn_clicked();

    void on_pl1_ag19_btn_clicked();

    void on_pl1_ag20_btn_clicked();

    void on_pl1_ag21_btn_clicked();

    void on_pl1_ag22_btn_clicked();

    void on_pl1_ag23_btn_clicked();

    void on_pl1_ag24_btn_clicked();

    void on_pl2_ag1_btn_clicked();

    void on_pl2_ag2_btn_clicked();

    void on_pl2_ag3_btn_clicked();

    void on_pl2_ag4_btn_clicked();

    void on_pl2_ag5_btn_clicked();

    void on_pl2_ag6_btn_clicked();

    void on_pl2_ag7_btn_clicked();

    void on_pl2_ag8_btn_clicked();

    void on_pl2_ag9_btn_clicked();

    void on_pl2_ag10_btn_clicked();

    void on_pl2_ag11_btn_clicked();

    void on_pl2_ag12_btn_clicked();

    void on_pl2_ag13_btn_clicked();

    void on_pl2_ag14_btn_clicked();

    void on_pl2_ag15_btn_clicked();

    void on_pl2_ag16_btn_clicked();

    void on_pl2_ag17_btn_clicked();

    void on_pl2_ag18_btn_clicked();

    void on_pl2_ag19_btn_clicked();

    void on_pl2_ag20_btn_clicked();

    void on_pl2_ag21_btn_clicked();

    void on_pl2_ag22_btn_clicked();

    void on_pl2_ag23_btn_clicked();

    void on_pl2_ag24_btn_clicked();

private:
    Ui::playingGameWindow *ui;
};

#endif // PLAYINGGAMEWINDOW_H
