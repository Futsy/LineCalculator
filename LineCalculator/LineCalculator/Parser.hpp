#ifndef PARSER_HPP
#define PARSER_HPP

#include <QString>

#include <cmath>
#include <map>
#include <memory>
#include <stack>
#include <vector>

#include <gmpxx.h>

#include "Operator.hpp"


enum class ReturnCode
{
	OK			= 0,
	EMPTY		= 1,
	PARENTHESIS = 2,
	VALUES      = 3,
	ZERODIV		= 4
};


class Parser 
{
public:
	Parser() 
	{
		m_operators.insert(std::make_pair('^', 0));
		m_operators.insert(std::make_pair('*', 1));
		m_operators.insert(std::make_pair('/', 2));
		m_operators.insert(std::make_pair('-', 3));
		m_operators.insert(std::make_pair('+', 4));
		m_operators.insert(std::make_pair('(', 5));
		m_operators.insert(std::make_pair(')', 6));
		m_operators.insert(std::make_pair('_', 7));
	}

public:
	int ToRPN(const QString& expression);
	int PostFixRPN();

private:
	std::stack<Operator> m_queue;
	std::stack<mpz_class> m_result;
	std::vector<QString> m_output;

	std::map<QChar, int> m_operators;	

	std::string m_solution;

};


#endif // PARSER_HPP