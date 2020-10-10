#include <cstdint>

class elapsed_time
{
public:
    typedef enum _ACCURACY {
        ACCURACY_MSEC,
        ACCURACY_USEC,
        ACCURACY_NSEC
    } ACCURACY;
private:
    double          start_;
    std::uint32_t   accuracy_;

public:
    elapsed_time(int accuracy = ACCURACY_USEC);
    elapsed_time(const elapsed_time& elapsed_time);
    ~elapsed_time();

    bool            start();
    std::uint64_t   stop() const;

private:
    inline double   get_current() const;
};
