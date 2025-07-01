/*✅ 1. Clear Explanation: What is std::find_if?
std::find_if is an STL algorithm that:
Takes a range (begin to end) and a predicate (lambda function)
Returns the first element that satisfies the condition
Returns an iterator to that element, or .end() if not found*/
#include <algorithm>
#include <vector>
#include <iostream>
struct Asset{
    std::string name;
    double score;
};
int main() {
    std::vector<double> returns = { -0.01, -0.02, 0.03, 0.07, 0.02 };

    auto it = std::find_if(returns.begin(), returns.end(),
                           [](double r) { return r > 0.05; });

    if (it != returns.end()) {
        std::cout << "Found high return: " << *it << "\n";
    } else {
        std::cout << "No return exceeds threshold\n";
    }


    // task 
    std::vector<Asset> Portfolio = {
        {"alpha1", 0.42},
        {"alpha2", 0.63},
        {"alpha3", 0.81},  
        {"alpha4", 0.72}
    };

    auto it2 = std::find_if(Portfolio.begin(), Portfolio.end(), [](const Asset& a){
        return a.score > 0.75;
    });

    if (it2 != Portfolio.end()) {
        Asset s = *it2;
        std::cout << "✅ Found: " << s.name << " with score = " << s.score << "\n";
    } else {
        std::cout << "❌ No signal with score > 0.75 found.\n";
    }
}
/*std::find_if = fast condition-based lookup

Non-allocating, efficient, in-place

Ideal for risk checks, alpha filters, and alert triggers

Scales well, safe for real-time and backtest*/