#include <assert.h>
#include <fstream>
#include <string>
#include <iostream>

namespace BlackBoxEngine
{
	template<typename Tested_t>
	concept StreamOverloaded = requires (std::ostream os,const Tested_t& obj)
	{
		{ os << obj } -> std::convertible_to<std::ostream&>;
	};

	class Logger
	{
	private:
		inline static std::fstream m_logFile;
		static constexpr const char* logFilePath = "..\\BlackBoxEngine_Build\\BlackBoxLog.txt";
	public:
		~Logger();
		static void AppendToLogFile(const char* str);
		template<StreamOverloaded ...Args>
		static void AppendToLogFile(const Args& ...args);
	};

	void Log(const std::string& string);
	void Log(const char* string);
	template <StreamOverloaded ... Args>
	void Log(const Args&... args);

	template<StreamOverloaded ...Args>
		inline void Log(const Args & ...args)
	{
		(std::cout << ... << args) << '\n';
		Logger::AppendToLogFile(args...);
	}

	template<StreamOverloaded ...Args>
	inline void Logger::AppendToLogFile(const Args&... args)
	{
		if (!m_logFile.is_open())
			m_logFile.open(logFilePath, std::ios::out); // Creates file for first time.

		assert(m_logFile.is_open());
		(m_logFile << ... << args) << '\n';
	}
}


