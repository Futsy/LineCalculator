#include "NumberParser.hpp"

#include <algorithm>


/**
 * Operator array
 * Used to confirm that a token is an operator
 */
QChar NumberParser::m_operators[] = {
	'(', ')', '*', '+', '-', '/', '^', '_'
};


/**
 * Shunting-yard algorithm
 * Info: http://en.wikipedia.org/wiki/Shunting-yard_algorithm
 * @param const QString& expression
 * @return int - ReturnCode enum
 */
int NumberParser::ToRPN(const QString& expression)
{
	//\todo: Possibly redundant when tokenized
	if (expression.trimmed().isEmpty()) {
		return static_cast<int>(ReturnCode::EMPTY);
	}

	m_output.clear();


	bool lastWasOperator = true;
	//! While there are tokens to be read: Read a token.
	for (int i = 0; i < expression.size(); i++) {
		const auto current = expression[i];

		//! If the token is a number, then add it to the output queue.
		//\todo: this does not accept numbers with dots (1234.1234)
		if (current.digitValue() != -1 || current == '.') {
			QString number = current;

			//! Eat digits untill something else appears
			for (int j = i + 1; j < expression.size(); j++, i++) {
				if (expression[j].digitValue() == -1 && expression[j] != '.') {
					break;
				}
				number += expression[j];
			}

			m_output.push_back(number);
			lastWasOperator = false;
		}
		
		//! Convert the current char to an operator
		char toChar = current.toLatin1();

		//! No operator
		if (!std::binary_search(std::begin(m_operators), std::end(m_operators), toChar)) {
			continue;
		}

		Operator currentOperator(toChar, lastWasOperator);
		if (currentOperator.m_precendence > 0) {
			//! while there is an operator token, o2, at the top of the stack
			while(!m_queue.empty() && 
				//and either o1 is left-associative and its precedence is less than or equal to that of o2
				((currentOperator.m_precendence > 0 && currentOperator.m_precendence != 4 
				&& currentOperator.m_precendence != 10 && m_queue.top().m_precendence >= currentOperator.m_precendence) 
				//or o1 has precedence less than that of o2,
				|| (m_queue.top().m_precendence > currentOperator.m_precendence))) {

				//! pop o2 off the stack, onto the output queue;				
				m_output.push_back(m_queue.top().m_token);
				m_queue.pop();
			}
			
			//! push o1 onto the stack.
			m_queue.push(currentOperator);
			lastWasOperator = true;
		}

		//! If the token is a left parenthesis, then push it onto the stack.
		if (currentOperator.m_token == '(') {
			m_queue.push(Operator('('));
		}
		
		//! If the token is a right parenthesis:
		if (currentOperator.m_token == ')') {
			//! Until the token at the top of the stack is a left parenthesis, pop operators off the stack onto the output queue.
			while (!m_queue.empty()) {
				if (m_queue.top().m_token == '(') {
					//! Pop the left parenthesis from the stack, but not onto the output queue.
					m_queue.pop();
					break;
				}

				m_output.push_back(m_queue.top().m_token);
				m_queue.pop();
			}

			//! If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.
			if (m_queue.empty()) {
				return static_cast<int>(ReturnCode::PARENTHESIS);
			}
		}
	}
	
	//! If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses.
	if (!m_queue.empty() && (m_queue.top().m_token == '(' || m_queue.top().m_token == ')')) {
		return static_cast<int>(ReturnCode::PARENTHESIS);
	}
	
	//! While there are still operator tokens in the stack:
	while (!m_queue.empty()) {
		//! Pop the operator onto the output queue.
		m_output.push_back(m_queue.top().m_token);
		m_queue.pop();
	}

	return static_cast<int>(ReturnCode::OK);
}


/**
 * Postfix algorithm
 * Info: http://en.wikipedia.org/wiki/Reverse_Polish_notation
 * @return int - ReturnCode enum
 */
int NumberParser::PostFixRPN() 
{
	//! Clear the result stack
	while (!m_result.empty()) {
		m_result.pop();
	}

	//! While there are input tokens left
	for (const auto& e : m_output) {
		//! If the token is a number (Maybe they entered .1234 which is correct check for that as well)
		if (e[0].digitValue() != -1 || (e.size() > 1 && e[1].digitValue() != -1)) {			
			//! Push it onto the stack.
			m_result.push(mpf_class(e.toStdString()));
		}
		else { 

			if (e[0].toLatin1() == '_') {
				m_result.top() *= -1;
				continue;
			}
			
			//! Evaluate the operator, with the values as arguments.
			//! Else, Pop the top n values from the stack.
			const mpf_class second	= m_result.top();
			m_result.pop();
			const mpf_class first	= m_result.top();
			m_result.pop();

			mpf_class result;
			switch (e[0].toLatin1()) {
			case '^':
				mpf_pow_ui(result.get_mpf_t(), first.__get_mp(), second.get_ui());
				m_result.push(result);
				break;

			case '*':
				m_result.push(first * second);
				break;

			case '/':
				if (second == 0) {
					return static_cast<int>(ReturnCode::ZERODIV);
				}
				m_result.push(first / second);
				break;

			case '-':
				m_result.push(first - second);
				break;

			case '+':
				m_result.push(first + second);
				break;

			}
		}
	}

	mp_exp_t exp;
	m_solution = m_result.top().get_str(exp);

	const int unaryOccurence = std::count(std::begin(m_solution), std::end(m_solution), '-');
	const int actualSize = m_solution.size() - unaryOccurence;
	for (int i = actualSize + 1; i <= exp; i++) {
		m_solution += "0";
	}
	

	if (exp != m_solution.size() - unaryOccurence) {
		m_solution.insert((exp + unaryOccurence < 0) ? 0 : exp + unaryOccurence, ".");
	}

	return static_cast<int>(ReturnCode::OK);	
}


/**
 * Function that returns the RPN Notation
 * @return QString
 */
QString NumberParser::GetRPN() const  {
	QString RPN = "";
	for (const auto& e : m_output) {
		RPN += e;
	}
	return RPN;
}