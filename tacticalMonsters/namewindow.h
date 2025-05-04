#ifndef NAMEWINDOW_H
#define NAMEWINDOW_H

#include <QWidget>

namespace Ui {
class nameWindow;
}

class nameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit nameWindow(QWidget *parent = nullptr);
    ~nameWindow();

private:
    Ui::nameWindow *ui;
};

#endif // NAMEWINDOW_H
