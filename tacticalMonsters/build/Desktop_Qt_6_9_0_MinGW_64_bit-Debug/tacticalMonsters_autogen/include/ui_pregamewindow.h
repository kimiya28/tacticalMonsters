/********************************************************************************
** Form generated from reading UI file 'pregamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREGAMEWINDOW_H
#define UI_PREGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_preGameWindow
{
public:
    QWidget *widget;
    QPushButton *galleryButton;
    QPushButton *startButton;

    void setupUi(QWidget *preGameWindow)
    {
        if (preGameWindow->objectName().isEmpty())
            preGameWindow->setObjectName("preGameWindow");
        preGameWindow->resize(960, 540);
        preGameWindow->setMinimumSize(QSize(960, 540));
        preGameWindow->setMaximumSize(QSize(960, 540));
        preGameWindow->setAutoFillBackground(false);
        preGameWindow->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(preGameWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 960, 540));
        widget->setMinimumSize(QSize(960, 540));
        widget->setMaximumSize(QSize(960, 540));
        widget->setStyleSheet(QString::fromUtf8("#widget{\n"
"background-image: url(:/src/images/second_win_bg.jpg);\n"
"}"));
        galleryButton = new QPushButton(widget);
        galleryButton->setObjectName("galleryButton");
        galleryButton->setGeometry(QRect(670, 110, 211, 41));
        galleryButton->setAutoFillBackground(false);
        galleryButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 28pt \"Niagara Engraved\";\n"
"	background-color: #fca852;\n"
"	color: #485aa4;\n"
"	border-radius: 20px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #e69542; \n"
"    }"));
        startButton = new QPushButton(widget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(530, 40, 351, 41));
        startButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 28pt \"Niagara Engraved\";\n"
"	background-color: #fca852;\n"
"	color: #485aa4;\n"
"	border-radius: 20px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #e69542; \n"
"    }"));

        retranslateUi(preGameWindow);

        galleryButton->setDefault(false);


        QMetaObject::connectSlotsByName(preGameWindow);
    } // setupUi

    void retranslateUi(QWidget *preGameWindow)
    {
        preGameWindow->setWindowTitle(QCoreApplication::translate("preGameWindow", "Tactical Monsters", nullptr));
        galleryButton->setText(QCoreApplication::translate("preGameWindow", "Gallery", nullptr));
        startButton->setText(QCoreApplication::translate("preGameWindow", "Start an Async PVP Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class preGameWindow: public Ui_preGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREGAMEWINDOW_H
