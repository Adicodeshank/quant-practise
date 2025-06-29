/*✅ 1. What is std::map?
A std::map<K, V> is:

A container that associates keys with values.

Automatically sorted by key.

Backed by a Red-Black Tree (balanced BST).

All operations (insert, erase, find) are O(log n).

Each key-value pair is stored in a heap-allocated node.

Each node holds:

Key and Value

Left, Right, Parent pointers

Red/Black flag*/
#include<iostream>
#include<map>

int main()
{
    std::map<std::string, double> price_map;

    price_map["AAPL"] = 179.3;
    price_map["GOOG"] = 145.1;

    std::cout << price_map["AAPL"];  // 179.3

    for (auto& price : price_map)
    std::cout << price.first << ": " << price.second << "\n";

    if (price_map.count("MSFT"))
    std::cout << "Exists!";

    ////////////////////////////////
    price_map.insert({"MSFT", 312.8});  // Won't overwrite if key exists

    std::map<std::string, double> live_prices;
    live_prices["AAPL"] = 180.5;
    //////////////////////////////////////////////////
    live_prices["AAPL"] = 182.3;  // overwrites previous
}
/*🧠 Memory Cost:
Element	Cost
Key & Value	sizeof(K) + sizeof(V)
Tree overhead	~24–32 bytes per node (pointers + flags)
Total	Heavy per element*/

/*| Feature        | `std::map`                              |
| -------------- | --------------------------------------- |
| Ordered        | ✅ Yes (by key)                          |
| Duplicates     | ❌ Keys must be unique                   |
| Lookup time    | O(log n)                                |
| Memory use     | Moderate to high (tree node overhead)   |
| Thread safety  | ❌ Not thread-safe                       |
| Real use cases | Ticker tracking, portfolio, time series |
*/