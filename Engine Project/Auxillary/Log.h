
#include <fstream>
#include <string>
#include <iostream>

namespace BlackBoxEngine
{
	template<typename Type_t>
	concept StreamOverloaded = requires (std::ostream os, Type_t type)
	{
		os << type;
	};

	class Logger
	{
	private:
		inline static std::fstream m_logFile;
		inline static bool m_fileOpened = false;
		static constexpr const char* logFilePath = "..\\BlackBoxEngine_Build\\BlackBoxLog.txt";
	public:
		~Logger();
		static void AppendToLogFile(const char* str);
	};

	void Log(const std::string& string);
	void Log(const char* string);

}