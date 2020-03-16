#include <iostream>
#include <fstream>
#include <thread>
#include <csignal>
#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>

// g++ -std=c++11 -o ofstream_test ofstream_test.cpp

namespace
{
  volatile std::sig_atomic_t gSignalStatus = 0;
}

void signal_handler(int signal)
{
  gSignalStatus = signal;
}

std::string getTimeStamp()
{
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(localtime(&now_c), "%Y%m%d_%H%M%S");
    return ss.str();
}

int main()
{
    // Install a signal handler
    std::signal(SIGINT, signal_handler);

    while (gSignalStatus == 0) {
        // 
        std::ofstream outputfile("test.txt", std::ios_base::app);
        outputfile << getTimeStamp() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }

    std::raise(SIGINT);
    std::cout << "handled signal" << std::endl;

    return 0;
}

//2020-03-12 17:21:09|io$ ps -C ofstream_test
//  PID TTY          TIME CMD
//24382 pts/19   00:00:00 ofstream_test
//2020-03-12 17:21:25|io$ sudo strace -t -p 24382
//[sudo] のパスワード: 
//strace: Process 24382 attached
//17:21:41 restart_syscall(<... resuming interrupted nanosleep ...>) = 0
//17:21:43 close(4)                       = 0
//17:21:43 open("test.txt", O_WRONLY|O_CREAT|O_APPEND, 0666) = 4
//17:21:43 lseek(4, 0, SEEK_END)          = 864
//17:21:43 stat("/etc/localtime", {st_mode=S_IFREG|0644, st_size=318, ...}) = 0
//17:21:43 write(4, "20200312_172143\n", 16) = 16
//17:21:43 nanosleep({2, 0}, NULL)        = 0
//17:21:45 close(4)                       = 0
//17:21:45 open("test.txt", O_WRONLY|O_CREAT|O_APPEND, 0666) = 4
//17:21:45 lseek(4, 0, SEEK_END)          = 880
//17:21:45 stat("/etc/localtime", {st_mode=S_IFREG|0644, st_size=318, ...}) = 0
//17:21:45 write(4, "20200312_172145\n", 16) = 16
//17:21:45 nanosleep({2, 0}, NULL)        = 0
//17:21:47 close(4)                       = 0
//17:21:47 open("test.txt", O_WRONLY|O_CREAT|O_APPEND, 0666) = 4
//17:21:47 lseek(4, 0, SEEK_END)          = 896
//17:21:47 stat("/etc/localtime", {st_mode=S_IFREG|0644, st_size=318, ...}) = 0
//17:21:47 write(4, "20200312_172147\n", 16) = 16
//17:21:47 nanosleep({2, 0}, NULL)        = 0
//17:21:49 close(4)                       = 0
//17:21:49 open("test.txt", O_WRONLY|O_CREAT|O_APPEND, 0666) = 4
//17:21:49 lseek(4, 0, SEEK_END)          = 912
//17:21:49 stat("/etc/localtime", {st_mode=S_IFREG|0644, st_size=318, ...}) = 0
//17:21:49 write(4, "20200312_172149\n", 16) = 16
//17:21:49 nanosleep({2, 0}, NULL)        = 0
//17:21:51 close(4)                       = 0
//17:21:51 open("test.txt", O_WRONLY|O_CREAT|O_APPEND, 0666) = 4
//17:21:51 lseek(4, 0, SEEK_END)          = 928
//17:21:51 stat("/etc/localtime", {st_mode=S_IFREG|0644, st_size=318, ...}) = 0
//17:21:51 write(4, "20200312_172151\n", 16) = 16
//17:21:51 nanosleep({2, 0}, ^Cstrace: Process 24382 detached
// <detached ...>
//2020-03-12 17:21:52|io$ kill -SIGINT 24382
//2020-03-12 17:22:12|io$
