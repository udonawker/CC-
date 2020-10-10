#include "elapsed_time.h"
#include <time.h>

elapsed_time::elapsed_time(
    int accuracy
)
    : start_(0.)
{
    switch (accuracy) {
    case ACCURACY_MSEC:
        accuracy_ = SHL_S_TO_MS;
        break;
    case ACCURACY_NSEC:
        accuracy_ = SHL_S_TO_NS;
        break;
    case ACCURACY_USEC:
    default:
        accuracy_ = SHL_S_TO_US;
    }
}

elapsed_time::elapsed_time(
    const elapsed_time& elapsed_time
)
    : start_(elapsed_time.start_)
	, accuracy_(elapsed_time.accuracy_)
{
}

elapsed_time::~elapsed_time()
{
}

bool elapsed_time::Start()
{
    start_ = get_current();
    
    return true;
}

std::uint64_t elapsed_time::Stop() const
{
    double time = 0.;
    
    if ((time = get_current()) < start_) {
        return 0;
    }
    
    time -= start_;
    
    return static_cast<std::uint64_t>(time * accuracy_);
}

inline double elapsed_time::get_current() const
{
    struct timespec ts{};
    
    ::clock_gettime(CLOCK_MONOTONIC, &ts);
    
    return ts.tv_sec + ((double)ts.tv_nsec * 1e-9);
}
