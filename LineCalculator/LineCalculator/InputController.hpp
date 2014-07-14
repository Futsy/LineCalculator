#ifndef INPUTCONTROLLER_HPP
#define INPUTCONTROLLER_HPP

#include <QPair>

#include "NumberParser.hpp"


class InputController 
{
public:
	QPair<QString, QString> ParseInput(const QString& input);

private:
	NumberParser m_parser;

};


#endif // INPUTCONTROLLER_HPP