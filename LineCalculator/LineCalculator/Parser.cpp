#include "Parser.hpp"

#include <algorithm>


/**
 * Shunting-yard algorithm
 * Info: http://en.wikipedia.org/wiki/Shunting-yard_algorithm
 * @param const QString& expression
 * @return int - ReturnCode enum
 */
int Parser::ToRPN(const QString& expression)
{
	if (expression.trimmed().isEmpty()) {
		return static_cast<int>(ReturnCode::EMPTY);
	}

	m_output.clear();


	//! While there are tokens to be read: Read a token.
	for (int i = 0; i < expression.size(); i++) {
		const auto current = expression[i];

		//! If the token is a number, then add it to the output queue.
		if (current.digitValue() != -1) {
			
			QString number = current;
			for (int j = i + 1; j < expression.size(); j++, i++) {
				if (expression[j].digitValue() != -1) {
					number += expression[j];
				}
				else {
					break;
				}
			}
			m_output.push_back(number);
		}
		
		//! Convert the current char to an operator
		char toChar = current.toLatin1();

		//! No operator
		if (m_operators.find(toChar) == std::end(m_operators)) {
			continue;
		}

		Operator currentOperator(toChar);
		//! Check for unary minus
		if (toChar == '-' && (i == 0 || m_queue.size() > 0)) {
			currentOperator.m_token = '_';
		}
		
		

		//! If the token is a function token, then push it onto the stack.
		//NYI

		//! If the token is a function argument separator (e.g., a comma):
			//! Until the token at the top of the stack is a left parenthesis, 
			//! pop operators off the stack onto the output queue. If no left 
			//! parentheses are encountered, either the separator was misplaced 
			//! or parentheses were mismatched.
		//NYI

		//! If the token is an operator, o1, then:
		if (currentOperator.m_precendence > 0) {
			//! while there is an operator token, o2, at the top of the stack
			while(!m_queue.empty() && 
				//and either o1 is left-associative and its precedence is less than or equal to that of o2
				((currentOperator.m_precendence > 0 && currentOperator.m_precendence != 4 && m_queue.top().m_precendence >= currentOperator.m_precendence) 
				//or o1 has precedence less than that of o2,
				|| (m_queue.top().m_precendence > currentOperator.m_precendence))) {

				//! pop o2 off the stack, onto the output queue;				
				m_output.push_back(m_queue.top().m_token);
				m_queue.pop();
			}
			
			//! push o1 onto the stack.
			m_queue.push(currentOperator);
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

			//! If the token at the top of the stack is a function token, pop it onto the output queue.
			//NYI

		}
	}
	//! When there are no more tokens to read:
	
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
int Parser::PostFixRPN() {
	//! Clear the result stack
	while (!m_result.empty()) {
		m_result.pop();
	}

	//! While there are input tokens left
	for (const auto& e : m_output) {
		//! If the token is a number
		if (e[0].digitValue() != -1) {			
			//! Push it onto the stack.
			m_result.push(mpz_class(e.toStdString()));
		}
		else { //! Otherwise, the token is an operator (operator here includes both operators and functions).
			//! It is known a priori that the operator takes n arguments.
			//Which would be: 2 in these cases, but can be more!! f(x, y, z)

			//! If there are fewer than n values on the stack
			if (m_result.size() < 2) {
				//! There could be a number that needs to be multiplied by -1
				if (m_result.size() > 0) {
					m_result.top() *= -1;
					continue;
				}
				else {
					//! (Error) The user has not input sufficient values in the expression.
					return static_cast<int>(ReturnCode::VALUES);
				}
			}
			
			//! Evaluate the operator, with the values as arguments.
			//! Else, Pop the top n values from the stack.
			const mpz_class second	= m_result.top();
			m_result.pop();
			const mpz_class first	= m_result.top();
			m_result.pop();

			mpz_class result;
			switch (e[0].toLatin1()) {
			case '^':
				mpz_ui_pow_ui(result.get_mpz_t(), first.get_ui(), second.get_ui());
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
			case '-':
				m_result.push(first - second);
				break;

			case '+':
				m_result.push(first + second);
				break;

			}
			//Push the returned results, if any, back onto the stack.
			
		}
	}

	//! If there is only one value in the stack
	//if (m_result.size() == 1) {
		//That value is the result of the calculation.
	m_solution = m_result.top().get_str();
	//}
	//else { //! Otherwise, there are more values in the stack
		//(Error) The user input has too many values.
	//	return static_cast<int>(ReturnCode::VALUES);
	//}
		
	return static_cast<int>(ReturnCode::OK);	
}