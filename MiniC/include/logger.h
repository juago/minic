#ifndef __LOG1_H__
#define __LOG1_H__

#include <sstream>
#include <string>
#include <stdio.h>

enum TLogLevel 
{
    logDEBUG, 
    logDEBUG1, 
    logDEBUG2,
    logDEBUG3, 
    logDEBUG4,
	logINFO,
    logWARNING,  
    logERROR, 
};

class Log
{
public:
    Log();
    virtual ~Log();
    std::ostringstream& Get(TLogLevel level = logINFO);
public:
    static TLogLevel& ReportingLevel();
    static std::string ToString(TLogLevel level);
    static TLogLevel FromString(const std::string& level);
	static void SetLogLevel(TLogLevel logLevel);
protected:
    std::ostringstream os;
private:
    Log(const Log&);
    Log& operator =(const Log&);

	static TLogLevel reportingLevel;
};

inline Log::Log()
{
}

inline std::ostringstream& Log::Get(TLogLevel level)
{
		os << " " << ToString(level) << ": ";
		os << std::string(level > reportingLevel ? level - reportingLevel : 0, '\t');
		return os;
}

inline Log::~Log()
{
    os << std::endl;
    fprintf(stderr, "%s", os.str().c_str());
    fflush(stderr);
}

inline TLogLevel& Log::ReportingLevel()
{
    reportingLevel = logDEBUG4;
    return reportingLevel;
}

inline void Log::SetLogLevel(TLogLevel logLevel)
{
	reportingLevel = logLevel;
}

inline std::string Log::ToString(TLogLevel level)
{
    static const char* const buffer[] = {"DEBUG", "DEBUG1", "DEBUG2", "DEBUG3", "DEBUG4", "INFO", "WARNING", "ERROR"};
    return buffer[level];
}

inline TLogLevel Log::FromString(const std::string& level)
{
    if (level == "DEBUG4")
        return logDEBUG4;
    if (level == "DEBUG3")
        return logDEBUG3;
    if (level == "DEBUG2")
        return logDEBUG2;
    if (level == "DEBUG1")
        return logDEBUG1;
    if (level == "DEBUG")
        return logDEBUG;
    if (level == "INFO")
        return logINFO;
    if (level == "WARNING")
        return logWARNING;
    if (level == "ERROR")
        return logERROR;
    Log().Get(logWARNING) << "Unknown logging level '" << level << "'. Using INFO level as default.";
    return logINFO;
}

typedef Log FILELog;

#define FILE_LOG(level) \
    if (level > FILELog::ReportingLevel()) ; \
    else Log().Get(level)

#endif //__LOG_H__
