#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    std::vector<int> prices = {100, 102, 98};
    std::for_each(prices.begin(), prices.end(), [](int p){
        std::cout << "Price: " << p << '\n';
    });

    int count_above_100 = std::count_if(prices.begin(), prices.end(), [](int p){
        return p > 100;
    });

    //auto it = std::find_if(begin, end, predicate);
    // Returns an iterator to the first matching element (or end if none match).
    auto it = std::find_if(prices.begin(), prices.end(), [](int p){
        return p < 99;
    });
    if (it != prices.end()) std::cout << "Found dip: " << *it;

    //std::all_of(begin, end, pred);   // true if ALL match
    // std::any_of(begin, end, pred);   // true if ANY match
    // std::none_of(begin, end, pred); // true if NONE match

    bool stable = std::all_of(prices.begin(), prices.end(), [](int p){
        return p > 95 && p < 105;
    });

    // transform 
    // Transforms each element from an input range into an output (or modifies in-place).
    // std::transform(begin, end, out_begin, function);
    // std::vector<double> prices = {100.0, 105.0, 110.0};
    std::vector<double> normalized(prices.size());

    // std::transform(prices.begin(), prices.end(), normalized.begin(), [](double p){
    //     return p / 100.0;
    // });

    for(auto& it : normalized)
    {
        std::cout<<"normalized vector"<<"\n";
        std::cout<<it<<"\n";
    }

    // repalce_if
    // Replaces values in-place that match a condition.
    // std::replace_if(begin, end, predicate, new_value);

    std::replace_if(prices.begin(), prices.end(), [](double p){
         return p > 110.0 || p < 90.0;
    }, 100.0);

    // remove_if
    // Moves matching elements to the end, does not erase.
    // auto new_end = std::remove_if(begin, end, predicate);
    // ============= You still need to erase from the container: ===========
    std::vector<double>prices2 = {100.0, 123.3, 345.2};
    // vec.erase(std::remove_if(vec.begin(), vec.end(), predicate), vec.end());
    prices.erase(std::remove_if(prices.begin(), prices.end(), [](double p){
        return p < 95.0;
    }), prices.end());


    // sorting
    // assending
    // std::sort(begin, end); // Ascending by default
    // desending
    std::sort(prices.begin(), prices.end(), std::greater<>());
    for(auto& it : prices)
    {
        std::cout<<"desending vector"<<"\n";
        std::cout<<it<<"\n";
    }

    // lower bound 
    // auto it = std::lower_bound(begin, end, value);
    std::vector<double> sorted_prices = {95.0, 100.0, 105.0};
    auto it2 = std::lower_bound(sorted_prices.begin(), sorted_prices.end(), 99.0);
    std::cout << "Lower bound of 99: " << *it2;
    
    /*
        🧮 Memory & Performance Insights
        🔹 transform, replace_if, remove_if
        In-place or destination vector

        No allocations unless you create a new vector

        Algorithms work on iterators — O(n)

        🔹 sort
        In-place, O(n log n)

        Heap-based quicksort by default (random-access iterators only)

        🔹 lower_bound
        O(log n)

        Binary search on sorted data (very fast, cache-friendly)
    */
    



}

/*
 | Function   | Purpose                               | Returns               |
| ---------- | ------------------------------------- | --------------------- |
| `for_each` | Do something for every element        | nothing (side effect) |
| `count_if` | Count elements that match a condition | `int` count           |
| `find_if`  | Find first match                      | iterator              |
| `all_of`   | True if all match condition           | `bool`                |
| `any_of`   | True if any match                     | `bool`                |
| `none_of`  | True if none match                    | `bool`                |

*/