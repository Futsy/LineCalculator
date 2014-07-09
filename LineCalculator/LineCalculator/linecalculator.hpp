#ifndef LINECALCULATOR_HPP
#define LINECALCULATOR_HPP

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
	Parser m_parser;

private:
	Ui::LineCalculatorClass ui;

};


#endif // LINECALCULATOR_HPP
