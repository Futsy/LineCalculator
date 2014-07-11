#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <QChar>


class Operator 
{
public:
	explicit Operator(char token, bool unary = false);

public:
	QChar m_token;
	int m_precendence;
		
};


#endif // OPERATOR_HPP