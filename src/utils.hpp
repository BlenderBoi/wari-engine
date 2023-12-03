#ifndef UTILS_H
#define UTILS_H

#if DEBUG_ENABLED

#include <chrono>
#include <iostream>


#define CLOCK_START auto start = std::chrono::high_resolution_clock::now();

#define CLOCK_END(function_name) \
        auto stop = std::chrono::high_resolution_clock::now(); \
        auto durationMicro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); \
        auto durationMilli = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); \
        std::cout << "Time taken by " << function_name << " in microseconds: " << durationMicro.count() << " us" << std::endl; \
        std::cout << "Time taken by " << function_name << " in milliseconds: " << durationMilli.count() << " ms" << std::endl;

#else
#define CLOCK_START
#define CLOCK_END(function_name)
#endif
#endif