#pragma once
#include <time.h>

class ProgressPrinter
{
public:
    ProgressPrinter(int total, int bar_length = 50);
    ~ProgressPrinter();
    void progress();

private:
    void print_progress(float percentage);
    int total;
    int bar_length;
    int completion{};
    float prev_printed_percentage;
    time_t start_time;
    time_t last_print;
};