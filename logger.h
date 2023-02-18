#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include "noncopyable.h"

#define LOG_INFO(LogmsgFormat, ...)                       \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::instance();              \
        logger.setLogLevel(INFO);                         \
        char buf[1024] = {0};                             \
        snprintf(buf, 1024, LogmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

#define LOG_ERROR(LogmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::instance();              \
        logger.setLogLevel(ERROR);                        \
        char buf[1024] = {0};                             \
        snprintf(buf, 1024, LogmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)

#define LOG_FATAL(LogmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::instance();              \
        logger.setLogLevel(FATAL);                        \
        char buf[1024] = {0};                             \
        snprintf(buf, 1024, LogmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)
#ifdef MUDUODEG
#define LOG_DEBUG(LogmsgFormat, ...)                      \
    do                                                    \
    {                                                     \
        Logger &logger = Logger::instance();              \
        logger.setLogLevel(DEBUG);                        \
        char buf[1024] = {0};                             \
        snprintf(buf, 1024, LogmsgFormat, ##__VA_ARGS__); \
        logger.log(buf);                                  \
    } while (0)
#else
#define LOG_DEBUG(LogmsgFormat, ...)
#endif

// 定义日志级别 INFO ERROR FATAL DEBUG

enum LogLevel
{
    INFO,
    ERROR,
    FATAL,
    DEBUG,
};

// 输出一个日志类（单例模式）

class Logger : noncopyable
{
public:
    static Logger &instance();
    // 设置日志级别
    void setLogLevel(int level);
    // 写日志
    void log(std::string msg);

private:
    int logLevel_;
    Logger() {}
    ~Logger(){}
};

#endif