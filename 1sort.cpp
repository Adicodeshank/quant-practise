#include<iostream>
#include<vector>
#include<algorithm>
struct Signal {
    std::string name;
    double score;
};
int main()
{
    std::vector<int> prices = {105, 101, 103, 99};
    std::sort(prices.begin(), prices.end());

    for (int p : prices) std::cout << p << " "; 

    std::sort(prices.begin(), prices.end(), std::greater<>());
    
    for (int p : prices) std::cout << p << " "; 

    std::vector<Signal> signals = {
        {"alpha1", 0.42}, {"alpha2", 0.75}, {"alpha3", 0.33}
    };

    std::sort(signals.begin(), signals.end(), [](const Signal& a, const Signal& b){
        return (a.score > b.score);
    });

    
}