/********************************************************************************
** Form generated from reading UI file 'hexagonwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEXAGONWIDGET_H
#define UI_HEXAGONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hexagonwidget
{
public:

    void setupUi(QWidget *hexagonwidget)
    {
        if (hexagonwidget->objectName().isEmpty())
            hexagonwidget->setObjectName("hexagonwidget");
        hexagonwidget->resize(400, 300);

        retranslateUi(hexagonwidget);

        QMetaObject::connectSlotsByName(hexagonwidget);
    } // setupUi

    void retranslateUi(QWidget *hexagonwidget)
    {
        hexagonwidget->setWindowTitle(QCoreApplication::translate("hexagonwidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hexagonwidget: public Ui_hexagonwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEXAGONWIDGET_H
