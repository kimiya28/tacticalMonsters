/********************************************************************************
** Form generated from reading UI file 'gallerywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GALLERYWINDOW_H
#define UI_GALLERYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_galleryWindow
{
public:
    QWidget *widget;

    void setupUi(QWidget *galleryWindow)
    {
        if (galleryWindow->objectName().isEmpty())
            galleryWindow->setObjectName("galleryWindow");
        galleryWindow->resize(960, 540);
        galleryWindow->setMinimumSize(QSize(960, 540));
        galleryWindow->setMaximumSize(QSize(960, 540));
        galleryWindow->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(galleryWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 960, 540));
        widget->setMinimumSize(QSize(960, 540));
        widget->setMaximumSize(QSize(960, 540));
        widget->setStyleSheet(QString::fromUtf8("#widget{\n"
"background-image: url(:/src/images/gallery.jpg);\n"
"background-position: center;\n"
"background-repeat: no-repeat;\n"
"}"));

        retranslateUi(galleryWindow);

        QMetaObject::connectSlotsByName(galleryWindow);
    } // setupUi

    void retranslateUi(QWidget *galleryWindow)
    {
        galleryWindow->setWindowTitle(QCoreApplication::translate("galleryWindow", "Gallery", nullptr));
    } // retranslateUi

};

namespace Ui {
    class galleryWindow: public Ui_galleryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GALLERYWINDOW_H
