#include <time.h>
#include "elapsed_time.h"

elapsed_time::elapsed_time(
    int accuracy
)
    : start_(0.)
{
    switch (accuracy) {
    case ACCURACY_MSEC:
        accuracy_ = 1000;
        break;
    case ACCURACY_NSEC:
        accuracy_ = 1000 * 1000 * 1000;
        break;
    case ACCURACY_USEC:
    default:
        accuracy_ = 1000 * 1000;
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

bool elapsed_time::start()
{
    start_ = get_current();

    return true;
}

std::uint64_t elapsed_time::stop() const
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
