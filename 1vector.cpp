#include<iostream>
#include<vector>
int main()
{
    // vector
    // A vector is a dynamic array — it automatically resizes and stores elements contiguously in memory.
    // Memory is allocated on the heap
    //Grows via capacity doubling, causing occasional reallocation =>This is expensive: involves a copy of all elements.

    std::vector<double> prices = {100.5, 101.2, 99.8}; // initialize

    prices.push_back(102.3);    // append value
    prices[1] = 100.0;          // modify
    std::cout << prices.size()<<"\n"; // number of elements
    for(const auto& price : prices)
    {
        std::cout<<price<<"\n";
    }

    prices.reserve(10000); // prevent reallocations (optimize memory)
    std::cout<<"size after reserve "<< prices.size()<<"\n";
    prices.insert(prices.begin(), 99.0); // insert at start
    prices.erase(prices.begin() + 1);    // remove 2nd element
    for(const auto& price : prices)
    {
        std::cout<<price<<"\n";
    }
    std::cout << "Size: " << prices.size() << ", Capacity: " << prices.capacity() << "\n";
}