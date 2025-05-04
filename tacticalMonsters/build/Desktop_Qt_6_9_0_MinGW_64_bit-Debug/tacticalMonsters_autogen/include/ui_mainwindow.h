/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *playButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(960, 540);
        MainWindow->setMinimumSize(QSize(960, 540));
        MainWindow->setMaximumSize(QSize(960, 540));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("#playButton{\n"
"background-color:#fca852;\n"
"font: 28pt \"Niagara Engraved\";\n"
"color:#485aa4;\n"
"border-radius:22px;\n"
"}\n"
"QMainWindow{\n"
"background-image: url(:/src/images/main_win _bg.jpg);\n"
"background-position: center;\n"
"background-repeat: no-repeat;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(370, 360, 220, 50));
        playButton->setMinimumSize(QSize(220, 50));
        playButton->setMaximumSize(QSize(220, 50));
        playButton->setAutoFillBackground(false);
        playButton->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Tactical Monsters", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
