#ifndef INPUTCONTROLLER_HPP
#define INPUTCONTROLLER_HPP

#include <QPair>

#include "Parser.hpp"


class InputController 
{
public:
	QPair<QString, QString> ParseInput(const QString& input);

private:
	Parser m_parser;

};


#endif // INPUTCONTROLLER_HPP