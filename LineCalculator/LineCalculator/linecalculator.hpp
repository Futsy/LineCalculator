#ifndef LINECALCULATOR_HPP
#define LINECALCULATOR_HPP

#include <QKeyEvent>
#include <QPainter>
#include <QSizeGrip>
#include <QtWidgets/QWidget>

#include "Parser.hpp"
#include "Settings.hpp"
#include "ui_linecalculator.h"


class LineCalculator : public QWidget
{
	Q_OBJECT

public:
	LineCalculator(QWidget* parent = 0);

private:
	QSizeGrip m_sizeGrip;
	Parser m_parser;


private:
	Ui::LineCalculatorClass ui;

private Q_SLOTS:
	void paintEvent(QPaintEvent* event);
	void resizeEvent(QResizeEvent* event);
	bool eventFilter(QObject* obj, QEvent* event);

};


#endif // LINECALCULATOR_HPP
