#include "ProgressPrinter.h"
#include <iostream>
#include <cmath>

ProgressPrinter::ProgressPrinter(int total, int bar_length) : total{total}, bar_length{bar_length}, start_time{time(0)}
{
    print_progress(0);
}

ProgressPrinter::~ProgressPrinter()
{
}

void ProgressPrinter::print_progress(float percentage)
{
    if (percentage > 1)
    {
        throw std::runtime_error("ProgressPrinter over 100%");
    }
    last_print = time(0);

    std::cerr << "  " << difftime(time(0), start_time) << " sec  ";
    int completed_bars = (int)(percentage * bar_length);

    for (auto i = completed_bars; i > 0; i--)
    {
        std::cerr << "#";
    }
    for (auto i = bar_length - completed_bars; i > 0; i--)
    {
        std::cerr << ".";
    }

    std::cerr << "  " << ceil(percentage * 100);
    if (percentage == 1)
    {
        std::cerr << "\n";
    }
    else
    {
        std::cerr << "%\r";
    }
}

void ProgressPrinter::progress()
{
    completion++;
    float percentage = (float)completion / (float)total;
    // std::cerr << difftime(time(0), last_print) << "\n";
    if (((percentage - prev_printed_percentage) > 0.01) || completion == total || (difftime(time(0), last_print) >= 1))
    {
        print_progress(percentage);
        prev_printed_percentage = percentage;
    }
}
