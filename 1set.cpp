/*
A std::set<T>:

Stores unique elements.

Automatically sorts them (ascending by default).

Backed by a balanced binary search tree (usually Red-Black Tree).

All insert, delete, search are O(log n).*/
#include<iostream>
#include<set>

int main()
{
    std::set<int> s = {5, 1, 3};

    s.insert(4);        // adds 4
    s.insert(3);        // won't add (3 already exists)

    std::cout << s.size()<<"\n";  // 4

    for (int x : s)
        std::cout << x << " ";  

    if (s.find(4) != s.end())
    std::cout << "Exists!";

    s.erase(3);  // removes 3
    for (int x : s)
        std::cout << x << " ";  

    auto it = s.lower_bound(4);  // first ≥ 4
    if (it != s.end()) std::cout<<"lower bound " << *it;

    // Task 2: Efficiently check if a price exists
    if (s.count(102)) {
    std::cout << "Seen before";
    }
    else
    {
        std::cout<<"not there "<<"\n";
    }
    // Task 3: Maintain a running set of "seen tickers"

    std::set<std::string> tickers;
tickers.insert("AAPL");
tickers.insert("GOOG");

   if (!tickers.count("MSFT"))
    tickers.insert("MSFT");

    for(auto tick:tickers)
    {
        std::cout<<tick;

    }
    std::cout<<"\n";
}
/*
| Feature           | Details                                                                        |
| ----------------- | ------------------------------------------------------------------------------ |
| Memory location   | Stored on **heap**, each node is dynamically allocated                         |
| Overhead          | Each element has **pointer + balance flags** (\~24 bytes)                      |
| Speed             | Insert/find/erase: **O(log n)**                                                |
| Compare to vector | Slower access than `std::vector`, but **faster insert/delete** for sorted data |
*/