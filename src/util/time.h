#ifndef TIME_H
#define TIME_H

#include <chrono>
#include <thread>


long getCurrentTime();
long getCurrentTimeNS();

void sleep(long ms);


#endif