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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LineCalculatorClass
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;

    void setupUi(QWidget *LineCalculatorClass)
    {
        if (LineCalculatorClass->objectName().isEmpty())
            LineCalculatorClass->setObjectName(QStringLiteral("LineCalculatorClass"));
        LineCalculatorClass->resize(498, 82);
        LineCalculatorClass->setMinimumSize(QSize(498, 82));
        horizontalLayout = new QHBoxLayout(LineCalculatorClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_2 = new QPushButton(LineCalculatorClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(LineCalculatorClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        lineEdit = new QLineEdit(LineCalculatorClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(LineCalculatorClass);

        QMetaObject::connectSlotsByName(LineCalculatorClass);
    } // setupUi

    void retranslateUi(QWidget *LineCalculatorClass)
    {
        LineCalculatorClass->setWindowTitle(QApplication::translate("LineCalculatorClass", "LineCalculator", 0));
        pushButton_2->setText(QApplication::translate("LineCalculatorClass", "PushButton", 0));
        pushButton->setText(QApplication::translate("LineCalculatorClass", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class LineCalculatorClass: public Ui_LineCalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINECALCULATOR_H
