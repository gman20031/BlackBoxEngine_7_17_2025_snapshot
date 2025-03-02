#include "Log.h"

#include <filesystem>
#include <iostream>
#include <assert.h> 


BlackBoxEngine::Logger::~Logger()
{
	m_logFile.close();
}

void BlackBoxEngine::Logger::AppendToLogFile(const char* str)
{
	if (!m_fileOpened)
	{
		m_logFile.open(logFilePath, std::ios::out); // Creates file for first time.
		m_fileOpened = true;
	}
	assert(m_logFile.is_open());

	m_logFile << str << '\n';
}

template<BlackBoxEngine::StreamOverloaded Type_t>
inline void BlackBoxEngine::Logger::AppendToLogFile(const Type_t& object)
{
	if (!m_fileOpened)
	{
		m_logFile.open(logFilePath, std::ios::out); // Creates file for first time.
		m_fileOpened = true;
	}
	assert(m_logFile.is_open());

	m_logFile << object << '\n';
}

void BlackBoxEngine::Log(const std::string& string)
{
	Log(string.c_str());
}

void BlackBoxEngine::Log(const char* string)
{
	std::cout << string << '\n';
	Logger::AppendToLogFile(string);
}

template<BlackBoxEngine::StreamOverloaded Type_t>
void BlackBoxEngine::Log(const Type_t& loggedObject)
{
	std::cout << loggedObject << '\n';
	Logger::AppendToLogFile(loggedObject);
}