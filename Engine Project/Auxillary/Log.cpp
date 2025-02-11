#include "Log.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <assert.h> 


static void AppendToLogFile(const char* str)
{
	std::filesystem::path logFilePath = "..\\BlackBoxEngine\\";
//#if _DEBUG 
//	logFilePath /= "Debug";
//#else
//	logFilePath /= "Release";
//#endif
//#if _Win64
//	logFilePath /= "x64";
//#elif _WIN32 
//	logFilePath /= "x86";
//#endif

	logFilePath /= "BlackBoxLog.txt";

	std::fstream logFile;
	static bool fileOpened = false;

	if (fileOpened)
		logFile.open(logFilePath, std::ios::app);
	else
		logFile.open(logFilePath, std::ios::out); // to create the file for the first time.

	assert(logFile.is_open());

	logFile << str << '\n';

	logFile.close();
}

void BlackBoxEngine::Log(const std::string& string)
{
	std::cout << string << '\n';
	AppendToLogFile(string.c_str());
}

void BlackBoxEngine::Log(const char* string)
{
	std::cout << string << '\n';
	AppendToLogFile(string);
}
