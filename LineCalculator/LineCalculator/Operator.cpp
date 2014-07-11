#include "Operator.hpp"


/**
 * Constructor
 * @param char token
 * @param bool lastWasOperator
 */
Operator::Operator(char token, bool unary)
	: m_token(token) 
{
	switch (m_token.toLatin1()) {
	case '^':
		m_precendence = 4;
		break;

	case '*':
	case '/':
		m_precendence = 3;
		break;

	case '-':
		if (unary) {
			m_token = '_';
			m_precendence = 10;
			break;
		}

	case '+':
		m_precendence = 2;
		break;

	case '(':
	case ')':
		m_precendence = 0;
		break;

	}
}