#include <iostream>
#include <memory>
#include <vector>
#include <limits>

std::shared_ptr<std::vector<double> > loadPrices() {
    auto prices = std::make_shared<std::vector<double>>();
    prices->push_back(100.0);
    prices->push_back(101.5);
    prices->push_back(99.8);
    prices->push_back(102.3);
    prices->push_back(100.7);
    (*prices).push_back(144);

    return prices;
}
double calculateAverage(const std::shared_ptr<std::vector<double>>& prices)
{
     double sum = 0.0;
    for (double price : *prices) {
        sum += price;
    }
    return sum / prices->size();
}

double findMin(const std::shared_ptr<std::vector<double>>& prices) {
    double min = std::numeric_limits<double>::max();
    for (double price : *prices) {
        if (price < min) min = price;
    }
    return min;
}

// Function to find max price
double findMax(const std::shared_ptr<std::vector<double>>& prices) {
    double max = std::numeric_limits<double>::min();
    for (double price : *prices) {
        if (price > max) max = price;
    }
    return max;
}


int main() {
    auto prices = loadPrices();  // shared_ptr to vector<double>

    std::cout << "📊 Price Series:\n";

    for (double price : *prices) {
        std::cout << price << "\n";
    }

    std::cout << "🔹 Average: " << calculateAverage(prices) << "\n";
    std::cout << "🔽 Min: " << findMin(prices) << "\n";
    std::cout << "🔼 Max: " << findMax(prices) << "\n";

    return 0;
}