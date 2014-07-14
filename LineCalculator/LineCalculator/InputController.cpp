#include "InputController.hpp"


/**
 * Function that handles the input from the user
 * @param const QString& input
 * @return QPair<QString, QString>	Interpreted, Result
 */
QPair<QString, QString> InputController::ParseInput(const QString& input)
{
	m_parser.ToRPN(input);
	const QString rpnNotation = m_parser.GetRPN();
	m_parser.PostFixRPN();

	return QPair<QString, QString>(rpnNotation, m_parser.GetSolution());
}

