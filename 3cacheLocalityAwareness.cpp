#include <vector>
#include <cmath>     // for sqrt
#include <iostream>
#include <iomanip>   // for setprecision

double compute_sharpe_ratio(const std::vector<double>& returns) {
    size_t n = returns.size();
    if (n == 0) return 0.0;

    double sum = 0.0;
    double sq_sum = 0.0;

    // Single pass: compute sum and squared sum
    for (double r : returns) {
        sum += r;
        sq_sum += r * r;
    }

    double mean = sum / n;
    double variance = (sq_sum / n) - (mean * mean);
    double stddev = std::sqrt(variance);

    return (stddev == 0.0) ? 0.0 : (mean / stddev);
}

int main() {
    std::vector<double> returns = {
        0.01, -0.02, 0.015, 0.005, -0.005, 0.007, -0.004, 0.013
    };

    double sharpe = compute_sharpe_ratio(returns);
    std::cout << std::fixed << std::setprecision(4)
              << "Sharpe Ratio: " << sharpe << '\n';

    return 0;
}
