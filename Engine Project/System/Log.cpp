#include "Log.h"

BlackBoxEngine::Logger::~Logger()
{
	if(m_logFile.is_open())
		m_logFile.close();
}

void BlackBoxEngine::Logger::AppendToLogFile(const char* str)
{
	if (!m_logFile.is_open())
		m_logFile.open(logFilePath, std::ios::out); // Creates file for first time.
	assert(m_logFile.is_open());

	m_logFile << str << '\n';
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
