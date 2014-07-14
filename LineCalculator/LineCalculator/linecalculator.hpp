#ifndef LINECALCULATOR_HPP
#define LINECALCULATOR_HPP

#include <QKeyEvent>
#include <QPainter>
#include <QSizeGrip>
#include <QtWidgets/QWidget>

#include "InputController.hpp"
#include "Settings.hpp"
#include "ui_linecalculator.h"


class LineCalculator : public QWidget
{
	Q_OBJECT

public:
	LineCalculator(QWidget* parent = 0);

private:
	QSizeGrip m_sizeGrip;
	InputController m_inputController;
	QPoint m_diff;

private:
	Ui::LineCalculatorClass ui;

private Q_SLOTS:
	void paintEvent(QPaintEvent* event);
	void resizeEvent(QResizeEvent* event);
	bool eventFilter(QObject* obj, QEvent* event);

	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);

	void changeEvent(QEvent* event);

};


#endif // LINECALCULATOR_HPP
