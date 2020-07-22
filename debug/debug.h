#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>
#include <stdarg.h>
#include <string>

#ifdef DEBUG
//#define debug((fmt), ...) log("%s:%s(%d) \n" fmt, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define debug(fmt, ...) { \
    std::string format("%s:%s(%d) "); \
    format.append(fmt); \
    format.append("\n"); \
    log(format.c_str(), __FILE__, __func__, __LINE__, ##__VA_ARGS__); \
}
#else
#define debug(...) /* Do nothing. */
#endif

void log(const char* pFormat, ...);

#endif // _DEBUG_H_
