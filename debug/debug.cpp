#include "Debug.h"

void log(const char* pFormat, ...) {
    char buffer[8192]{};
    va_list arg;

    ::va_start(arg, pFormat);
    ::vsnprintf(buffer, sizeof(buffer), pFormat, arg);
    ::va_end(arg);

    ::printf(buffer);
}
