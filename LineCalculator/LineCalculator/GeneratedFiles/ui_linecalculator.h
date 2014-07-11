/********************************************************************************
** Form generated from reading UI file 'linecalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINECALCULATOR_H
#define UI_LINECALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LineCalculatorClass
{
public:
    QLineEdit *lineEdit;

    void setupUi(QWidget *LineCalculatorClass)
    {
        if (LineCalculatorClass->objectName().isEmpty())
            LineCalculatorClass->setObjectName(QStringLiteral("LineCalculatorClass"));
        LineCalculatorClass->resize(600, 98);
        lineEdit = new QLineEdit(LineCalculatorClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 50, 261, 20));

        retranslateUi(LineCalculatorClass);

        QMetaObject::connectSlotsByName(LineCalculatorClass);
    } // setupUi

    void retranslateUi(QWidget *LineCalculatorClass)
    {
        LineCalculatorClass->setWindowTitle(QApplication::translate("LineCalculatorClass", "LineCalculator", 0));
    } // retranslateUi

};

namespace Ui {
    class LineCalculatorClass: public Ui_LineCalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINECALCULATOR_H
