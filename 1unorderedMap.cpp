/*| Feature              | Value                             |
| -------------------- | --------------------------------- |
| Lookup Time          | **O(1)** average (amortized)      |
| Maintains Order?     | ❌ No                              |
| Underlying Structure | Hash Table with Buckets           |
| Use Case             | Fast key-value access, non-sorted |
*/
#include <unordered_map>
#include <string>
#include <iostream>
int main()
{
    std::unordered_map<std::string, double> price_map;
    price_map["AAPL"] = 179.3;
    price_map["MSFT"] = 312.1;

    if (price_map.count("AAPL")) {
        // To check if a key exists — nothing more.
        /*✅ Returns:
            0 → key not present
            1 → key present (since keys are unique in unordered_map)
            O(1) average time (very fast)
        */
        std::cout << "AAPL Price: " << price_map["AAPL"] << "\n";
    }

    for (auto& price : price_map)
        std::cout << price.first << ": " << price.second << "\n";

    auto it = price_map.find("AAPL");
    // ✅ Purpose:
    // To get an iterator to the key-value pair.
    /*✅ Returns:
    iterator to the key-value pair if found
    end() if not found
    O(1) average time*/
    if (it != price_map.end())
        std::cout << "Price: " << it->second;

    
}

/*| Component              | Bytes (64-bit)                             |
| ---------------------- | ------------------------------------------ |
| Key (e.g., string)     | Depends, usually heap-allocated            |
| Value (e.g., double)   | 8 bytes                                    |
| Node struct + overhead | \~32–48 bytes per element                  |
| Hash table buckets     | Grows exponentially (`load_factor` capped) |
*/


