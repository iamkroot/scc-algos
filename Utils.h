#ifndef UTILS_H
#define UTILS_H

#include <chrono>
#include <vector>

std::vector<std::pair<int, int>> readEdgeList(const std::string &path);

template<typename TimeT = std::chrono::microseconds,
        typename ClockT = std::chrono::high_resolution_clock,
        typename DurationT = uint64_t>
class Stopwatch {
private:
    std::chrono::time_point<ClockT> _start, _end;
public:
    Stopwatch() {
        start();
    }

    void start() {
        _start = _end = ClockT::now();
    }

    DurationT stop() {
        _end = ClockT::now();
        return elapsed();
    }

    DurationT elapsed() {
        auto delta = std::chrono::duration_cast<TimeT>(_end - _start);
        return delta.count();
    }

};

#endif //UTILS_H
