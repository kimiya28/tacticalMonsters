/********************************************************************************
** Form generated from reading UI file 'playinggamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYINGGAMEWINDOW_H
#define UI_PLAYINGGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playingGameWindow
{
public:
    QWidget *widget;
    QWidget *player1board;
    QLabel *label;
    QWidget *pl1_ag1_widget;
    QWidget *pl1_ag1_feature1;
    QWidget *pl1_ag1_feature2;
    QPushButton *pl1_ag1;
    QWidget *pl1_ag2_widget;
    QWidget *pl1_ag2_feature1;
    QWidget *pl1_ag2_feature2;
    QPushButton *pl1_ag2;
    QWidget *player2board;
    QLabel *label_2;
    QWidget *pl2_ag1_widget;
    QWidget *pl2_ag1_feature1;
    QWidget *pl2_ag1_feature2;
    QWidget *pl2_ag1;
    QWidget *pl2_ag2_widget;
    QWidget *pl2_ag2_feature1;
    QWidget *pl2_ag2_feature2;
    QWidget *pl2_ag2;
    QFrame *frame;
    QLabel *messageBox;

    void setupUi(QWidget *playingGameWindow)
    {
        if (playingGameWindow->objectName().isEmpty())
            playingGameWindow->setObjectName("playingGameWindow");
        playingGameWindow->resize(960, 540);
        playingGameWindow->setMinimumSize(QSize(960, 540));
        playingGameWindow->setMaximumSize(QSize(960, 540));
        widget = new QWidget(playingGameWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 960, 540));
        widget->setMinimumSize(QSize(960, 540));
        widget->setMaximumSize(QSize(960, 540));
        widget->setStyleSheet(QString::fromUtf8(""));
        player1board = new QWidget(widget);
        player1board->setObjectName("player1board");
        player1board->setGeometry(QRect(30, 40, 160, 440));
        player1board->setMinimumSize(QSize(160, 440));
        player1board->setMaximumSize(QSize(160, 16777215));
        player1board->setStyleSheet(QString::fromUtf8("#player1board{\n"
"background-image:url(:/src/images/clear-dark-gray-wall_1194-7279.jpg);\n"
"border-radius:20px;\n"
"}"));
        label = new QLabel(player1board);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 141, 31));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: #ffffff;\n"
"	border-radius: 20px;\n"
"	font: 28pt \"Niagara Engraved\";\n"
"}\n"
"\n"
""));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pl1_ag1_widget = new QWidget(player1board);
        pl1_ag1_widget->setObjectName("pl1_ag1_widget");
        pl1_ag1_widget->setGeometry(QRect(10, 69, 140, 70));
        pl1_ag1_widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: #808080;\n"
"border-radius:10px;\n"
"}"));
        pl1_ag1_feature1 = new QWidget(pl1_ag1_widget);
        pl1_ag1_feature1->setObjectName("pl1_ag1_feature1");
        pl1_ag1_feature1->setGeometry(QRect(70, 35, 25, 25));
        pl1_ag1_feature1->setStyleSheet(QString::fromUtf8("#pl1_ag1_feature1{\n"
"background-image:url(:/src/images/diamond.jpg);\n"
"}"));
        pl1_ag1_feature2 = new QWidget(pl1_ag1_widget);
        pl1_ag1_feature2->setObjectName("pl1_ag1_feature2");
        pl1_ag1_feature2->setGeometry(QRect(105, 35, 25, 25));
        pl1_ag1_feature2->setStyleSheet(QString::fromUtf8("#pl1_ag1_feature2{\n"
"background-image:url(:/src/images/heart.jpg);\n"
"}"));
        pl1_ag1 = new QPushButton(pl1_ag1_widget);
        pl1_ag1->setObjectName("pl1_ag1");
        pl1_ag1->setGeometry(QRect(12, 12, 50, 50));
        pl1_ag1->setStyleSheet(QString::fromUtf8(""));
        pl1_ag2_widget = new QWidget(player1board);
        pl1_ag2_widget->setObjectName("pl1_ag2_widget");
        pl1_ag2_widget->setGeometry(QRect(10, 160, 140, 70));
        pl1_ag2_widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: #808080;\n"
"border-radius:10px;\n"
"}"));
        pl1_ag2_feature1 = new QWidget(pl1_ag2_widget);
        pl1_ag2_feature1->setObjectName("pl1_ag2_feature1");
        pl1_ag2_feature1->setGeometry(QRect(70, 35, 25, 25));
        pl1_ag2_feature1->setStyleSheet(QString::fromUtf8("#pl1_ag2_feature1{\n"
"background-image:url(:/src/images/money.jpg);\n"
"}"));
        pl1_ag2_feature2 = new QWidget(pl1_ag2_widget);
        pl1_ag2_feature2->setObjectName("pl1_ag2_feature2");
        pl1_ag2_feature2->setGeometry(QRect(105, 35, 25, 25));
        pl1_ag2_feature2->setStyleSheet(QString::fromUtf8("#pl1_ag2_feature2{\n"
"background-image:url(:/src/images/power.jpg);\n"
"}"));
        pl1_ag2 = new QPushButton(pl1_ag2_widget);
        pl1_ag2->setObjectName("pl1_ag2");
        pl1_ag2->setGeometry(QRect(12, 12, 50, 50));
        player2board = new QWidget(widget);
        player2board->setObjectName("player2board");
        player2board->setGeometry(QRect(770, 40, 160, 440));
        player2board->setMinimumSize(QSize(160, 440));
        player2board->setMaximumSize(QSize(160, 440));
        player2board->setStyleSheet(QString::fromUtf8("#player2board{\n"
"background-image:url(:/src/images/clear-dark-gray-wall_1194-7279.jpg);\n"
"border-radius:20px;\n"
"}"));
        label_2 = new QLabel(player2board);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 141, 41));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: #ffffff;\n"
"	border-radius: 20px;\n"
"	font: 28pt \"Niagara Engraved\";\n"
"}"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pl2_ag1_widget = new QWidget(player2board);
        pl2_ag1_widget->setObjectName("pl2_ag1_widget");
        pl2_ag1_widget->setGeometry(QRect(10, 70, 140, 70));
        pl2_ag1_widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: #808080;\n"
"border-radius:10px;\n"
"}"));
        pl2_ag1_feature1 = new QWidget(pl2_ag1_widget);
        pl2_ag1_feature1->setObjectName("pl2_ag1_feature1");
        pl2_ag1_feature1->setGeometry(QRect(70, 35, 25, 25));
        pl2_ag1_feature1->setStyleSheet(QString::fromUtf8("#pl2_ag1_feature1{\n"
"background-image:url(:/src/images/power.jpg);\n"
"}"));
        pl2_ag1_feature2 = new QWidget(pl2_ag1_widget);
        pl2_ag1_feature2->setObjectName("pl2_ag1_feature2");
        pl2_ag1_feature2->setGeometry(QRect(105, 35, 25, 25));
        pl2_ag1_feature2->setStyleSheet(QString::fromUtf8("#pl2_ag1_feature2{\n"
"background-image:url(:/src/images/heart.jpg);\n"
"}"));
        pl2_ag1 = new QWidget(pl2_ag1_widget);
        pl2_ag1->setObjectName("pl2_ag1");
        pl2_ag1->setGeometry(QRect(10, 10, 50, 50));
        pl2_ag1->setStyleSheet(QString::fromUtf8("#pl2_ag1{\n"
"background-image:url(:/src/images/agent3.jpeg);\n"
"}\n"
""));
        pl2_ag2_widget = new QWidget(player2board);
        pl2_ag2_widget->setObjectName("pl2_ag2_widget");
        pl2_ag2_widget->setGeometry(QRect(10, 160, 140, 70));
        pl2_ag2_widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: #808080;\n"
"border-radius:10px;\n"
"}"));
        pl2_ag2_feature1 = new QWidget(pl2_ag2_widget);
        pl2_ag2_feature1->setObjectName("pl2_ag2_feature1");
        pl2_ag2_feature1->setGeometry(QRect(70, 35, 25, 25));
        pl2_ag2_feature1->setStyleSheet(QString::fromUtf8("#pl2_ag2_feature1{\n"
"background-image:url(:/src/images/diamond.jpg);\n"
"background-repeat:no-repeat;\n"
"background-position:center;\n"
"background-attachment:fixed;\n"
"backgroung-size:cover;\n"
"}"));
        pl2_ag2_feature2 = new QWidget(pl2_ag2_widget);
        pl2_ag2_feature2->setObjectName("pl2_ag2_feature2");
        pl2_ag2_feature2->setGeometry(QRect(105, 35, 25, 25));
        pl2_ag2_feature2->setStyleSheet(QString::fromUtf8("#pl2_ag2_feature2{\n"
"background-image:url(:/src/images/money.jpg);\n"
"}"));
        pl2_ag2 = new QWidget(pl2_ag2_widget);
        pl2_ag2->setObjectName("pl2_ag2");
        pl2_ag2->setGeometry(QRect(10, 10, 50, 50));
        pl2_ag2->setStyleSheet(QString::fromUtf8("#pl2_ag2{\n"
"background-image:url(:/src/images/agent4.jpg);\n"
"}\n"
""));
        frame = new QFrame(widget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 961, 541));
        frame->setStyleSheet(QString::fromUtf8("background-image:url(\":/src/images/play_ground.jpg\");"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        messageBox = new QLabel(widget);
        messageBox->setObjectName("messageBox");
        messageBox->setGeometry(QRect(320, 460, 320, 40));
        messageBox->setStyleSheet(QString::fromUtf8("    color: #ffffff;\n"
"	font: 28pt \"Niagara Engraved\";\n"
""));
        messageBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame->raise();
        player1board->raise();
        player2board->raise();
        messageBox->raise();

        retranslateUi(playingGameWindow);

        QMetaObject::connectSlotsByName(playingGameWindow);
    } // setupUi

    void retranslateUi(QWidget *playingGameWindow)
    {
        playingGameWindow->setWindowTitle(QCoreApplication::translate("playingGameWindow", "Tactical Monsters", nullptr));
        label->setText(QCoreApplication::translate("playingGameWindow", "PLAYER 1 TEAM ", nullptr));
        pl1_ag1->setText(QString());
        pl1_ag2->setText(QString());
        label_2->setText(QCoreApplication::translate("playingGameWindow", "PLAYER 2 TEAM", nullptr));
        messageBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class playingGameWindow: public Ui_playingGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYINGGAMEWINDOW_H
