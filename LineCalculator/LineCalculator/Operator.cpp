#include "Operator.hpp"


/**
 * Constructor
 * @param char token
 */
Operator::Operator(char token) {
	m_token = token;
	switch (m_token.toLatin1()) {
	case '^':
		m_precendence = 4;
		break;
	case '*':
	case '/':
		m_precendence = 3;
		break;
	case '-':
	case '+':
		m_precendence = 2;
		break;
	case '(':
	case ')':
		m_precendence = 0;
		break;
	}
}