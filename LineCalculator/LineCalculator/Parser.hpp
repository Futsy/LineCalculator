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
	int		ToRPN(const QString& expression);
	int		PostFixRPN();
	QString GetSolution() const { return QString::fromStdString(m_solution); }

private:
	std::stack<Operator>		m_queue;
	std::stack<mpf_class>		m_result;
	std::vector<QString>		m_output;	
	std::string					m_solution;
	static QChar				m_operators[];

};


#endif // PARSER_HPP