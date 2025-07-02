#include <chrono>
#include <iostream>
#include<vector>
struct Signal {
    double score;
};
int main()
{
auto start = std::chrono::high_resolution_clock::now();

// std::vector<Signal*> signals;
// for (int i = 0; i < 1'000'000; ++i)
//     signals.push_back(new Signal{(double)i});

// double sum = 0.0;
// for (Signal* s : signals)
//     sum += s->score;

std::vector<Signal> signals;
signals.reserve(1'000'000);
for (int i = 0; i < 1'000'000; ++i)
    signals.push_back({(double)i});

double sum = 0.0;
for (const Signal& s : signals)
    sum += s.score;

auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end - start;
std::cout << "Loop Time: " << diff.count() << " s\n";
}