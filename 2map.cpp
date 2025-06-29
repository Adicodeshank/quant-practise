///////////// time series price store 
#include <map>
#include <iostream>
int main()
{
    
std::map<int, double> price_series;  // timestamp → price

// Insert ticks
price_series[1001] = 101.0;
price_series[1002] = 102.5;
price_series[1003] = 103.0;

// Moving average over last 3 timestamps
double sum = 0.0;
int count = 0;

for (auto it = price_series.rbegin(); it != price_series.rend() && count < 3; ++it) {
    sum += it->second;
    ++count;
}

std::cout << "3-tick MA: " << sum / count << "\n";
}