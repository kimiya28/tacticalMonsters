#ifndef GALLERYWINDOW_H
#define GALLERYWINDOW_H

#include <QWidget>

namespace Ui {
class galleryWindow;
}

class galleryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit galleryWindow(QWidget *parent = nullptr);
    ~galleryWindow();

private slots:
    void on_backButton1_clicked();

    void on_backButton2_clicked();

    void on_backButton3_clicked();

    void on_backButton4_clicked();

private:
    Ui::galleryWindow *ui;

signals:
    void backToPreGameWindow();
};

#endif // GALLERYWINDOW_H
