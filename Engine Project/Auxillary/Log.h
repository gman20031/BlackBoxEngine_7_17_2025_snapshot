#include <string>

#include <fstream>


namespace BlackBoxEngine
{
	class Logger
	{
	private:
		inline static std::fstream m_logFile;
		inline static bool m_fileOpened = false;
		static constexpr const char* logFilePath = "..\\BlackBoxEngine\\BlackBoxLog.txt";
	public:
		~Logger();
		static void AppendToLogFile(const char* str);
	};

	void Log(const std::string& string);
	void Log(const char* string);

}