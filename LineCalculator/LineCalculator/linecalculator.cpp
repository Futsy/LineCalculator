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

	//5 + ((1 + 2) * 4) - 3 = 14
	//3 + 4 * 2 / (1 - 5) ^ 2 ^ 3 = 3
	//3 * 3 * 3 - 1 = 26

	m_parser.ToRPN("3 * -5");
	m_parser.PostFixRPN();

	//! Use settings to set application information
	setWindowTitle(Settings::m_applicationTitle + " - " 
		+ Settings::m_applicationVersion
		+ static_cast<char>(Settings::m_applicationStage));

}









