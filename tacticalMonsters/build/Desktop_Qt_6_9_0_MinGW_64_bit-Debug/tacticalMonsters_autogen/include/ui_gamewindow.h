/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameWindow
{
public:
    QWidget *widget;
    QLabel *label_2;
    QLabel *label;
    QPushButton *startGameButton;
    QPlainTextEdit *player2Name;
    QPlainTextEdit *player1Name;
    QLabel *label_3;

    void setupUi(QWidget *gameWindow)
    {
        if (gameWindow->objectName().isEmpty())
            gameWindow->setObjectName("gameWindow");
        gameWindow->resize(960, 540);
        gameWindow->setMinimumSize(QSize(960, 540));
        gameWindow->setMaximumSize(QSize(960, 540));
        gameWindow->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(gameWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 960, 540));
        widget->setMinimumSize(QSize(960, 540));
        widget->setMaximumSize(QSize(960, 540));
        widget->setStyleSheet(QString::fromUtf8("#widget{\n"
"background-image:url(\":/src/images/game_win_bg.jpg\");\n"
"}"));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(729, 216, 71, 41));
        label_2->setStyleSheet(QString::fromUtf8("#label_2{\n"
"font: 28pt \"Niagara Engraved\";\n"
"color:#ffffff;\n"
"}"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 217, 71, 41));
        label->setStyleSheet(QString::fromUtf8("#label{\n"
"font: 28pt \"Niagara Engraved\";\n"
"color:#ffffff;\n"
"}"));
        startGameButton = new QPushButton(widget);
        startGameButton->setObjectName("startGameButton");
        startGameButton->setGeometry(QRect(340, 360, 261, 61));
        startGameButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #fca852;\n"
"	color: #485aa4;\n"
"	border-radius: 20px;\n"
"	font: 28pt \"Niagara Engraved\";\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: #e69542; \n"
"    }"));
        player2Name = new QPlainTextEdit(widget);
        player2Name->setObjectName("player2Name");
        player2Name->setGeometry(QRect(610, 260, 311, 51));
        player2Name->setStyleSheet(QString::fromUtf8("#player2Name{\n"
"background-color:#c24847;\n"
"font: 28pt \"Niagara Engraved\";\n"
"color:#ffffff;\n"
"border-radius:22px;\n"
"}"));
        player1Name = new QPlainTextEdit(widget);
        player1Name->setObjectName("player1Name");
        player1Name->setGeometry(QRect(20, 260, 281, 51));
        player1Name->setStyleSheet(QString::fromUtf8("#player1Name{\n"
"background-color:#3a83c8;\n"
"font: 28pt \"Niagara Engraved\";\n"
"color:#ffffff;\n"
"border-radius:22px;\n"
"}"));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(370, 450, 211, 41));
        label_3->setStyleSheet(QString::fromUtf8("#label_3{\n"
"font: 28pt \"Niagara Engraved\";\n"
"color:#485aa4;\n"
"}"));

        retranslateUi(gameWindow);

        QMetaObject::connectSlotsByName(gameWindow);
    } // setupUi

    void retranslateUi(QWidget *gameWindow)
    {
        gameWindow->setWindowTitle(QCoreApplication::translate("gameWindow", "TacticalMonsters", nullptr));
        label_2->setText(QCoreApplication::translate("gameWindow", "player2", nullptr));
        label->setText(QCoreApplication::translate("gameWindow", "player1", nullptr));
        startGameButton->setText(QCoreApplication::translate("gameWindow", "START GAME", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gameWindow: public Ui_gameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
