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

private:
    Ui::galleryWindow *ui;
};

#endif // GALLERYWINDOW_H
