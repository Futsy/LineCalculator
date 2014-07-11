#include "linecalculator.hpp"


/**
 * Constructor for the LineCalculator window
 * @param QWidget* parent
 */
LineCalculator::LineCalculator(QWidget* parent)
	: QWidget(parent),
	m_parser()
{
	ui.setupUi(this);
	installEventFilter(this);

	//! Cut the window
	setWindowFlags(Qt::FramelessWindowHint);


	//m_parser.ToRPN("3 + 4");
	//m_parser.PostFixRPN();

	//! Use settings to set application information
	setWindowTitle(Settings::m_applicationTitle + " - " 
		+ Settings::m_applicationVersion
		+ static_cast<char>(Settings::m_applicationStage));

}


/**
 * Function that draws redraws the window
 * @param QPaintEvent* event
 */
void LineCalculator::paintEvent(QPaintEvent* event)
{ 
	QPainter painter(this);
  
	QBrush background(QColor(255, 255, 255));
	QPen border(QColor(190, 190, 190));

	painter.setBrush(background);
	painter.setPen(Qt::SolidLine);
	painter.setPen(border);

	//! Draw the rectangle in the original frame (subtract 1 to get right and bottom line)
	painter.drawRect(0, 0, width() - 1, height() - 1);
}


/**
 * Function that starts computation if user pressed enter
 * @param QObject* obj
 * @param QEvent* event
 * @return bool - true on enter else eventFilter
 */
bool LineCalculator::eventFilter(QObject* obj, QEvent* event)
{
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent* key = static_cast<QKeyEvent*>(event);

		if (key->key() == Qt::Key_Enter || key->key() == Qt::Key_Return) {
			m_parser.ToRPN(ui.lineEdit->text());
			m_parser.PostFixRPN();
			ui.lineEdit->setText(m_parser.GetSolution());
			
			return true;
		}
	}
	return QObject::eventFilter(obj, event);
}


