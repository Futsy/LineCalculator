#include "InputController.hpp"


/**
 * Function that handles the input from the user
 * @param const QString& input
 * @return QPair<QString, QString>	Interpreted, Result
 */
QPair<QString, QString> InputController::ParseInput(const QString& input)
{
	//! Parse to RPN
	QString rpnNotation;
	switch (m_parser.ToRPN(input)) {
	case ReturnCode::OK:
		rpnNotation = m_parser.GetRPN();
		break;

	case ReturnCode::EMPTY:
		return QPair<QString, QString>("Empty input", input);

	case ReturnCode::PARENTHESIS:
		return QPair<QString, QString>("Mismatch parenthesis", input);

	default:
		return QPair<QString, QString>("Undefined error", input);

	}
	
	//! Parse to solution
	QString solution;
	switch (m_parser.PostFixRPN()) {
	case ReturnCode::OK:
		return QPair<QString, QString>(rpnNotation, m_parser.GetSolution());
	
	case ReturnCode::ZERODIV:
		return QPair<QString, QString>("Division by zero", input);

	default:
		return QPair<QString, QString>("Undefined error", input);

	}
}

