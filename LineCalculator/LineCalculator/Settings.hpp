#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QString>


enum class StageType : char 
{
	ALPHA	= 'A',
	BETA	= 'B',
	RELEASE = ' '
};


class Settings 
{
public:
	//! Calculation time in miliseconds
	static int m_calculateDuration;

	//! Application title
	static QString m_applicationTitle;

	//! Application version
	static QString m_applicationVersion;

	//! Application stage
	static StageType m_applicationStage;

};


#endif // SETTINGS_HPP