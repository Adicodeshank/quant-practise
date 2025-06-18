/*Move Semantics is C++'s way of stealing resources instead of copying them.
This is enabled through rvalue references (T&&), which represent temporary objects — values you won’t use again.*/

/*Intution 
| Operation | Copy Semantics                   | Move Semantics                                    |
| --------- | -------------------------------- | ------------------------------------------------- |
| Behavior  | Creates a deep copy (expensive)  | Transfers ownership, leaves original empty (fast) |
| Use Case  | When you still need the original | When original is disposable                       |
*/

#include<iostream>
#include<memory>
#include<utility>
#include<vector>
class TickData {
private:
    std::vector<double> ticks;
public:
    // Constructor (copy)
    TickData(const std::vector<double>& t) : ticks(t) {
        std::cout << "Copied\n";
    }

    // Move constructor
    TickData(std::vector<double>&& t) : ticks(std::move(t)) {
        std::cout << "Moved\n";
    }
};
class QuantMatrix {
private:
    std::vector<std::vector<double>>prices;
public:
    // copy constructer  => const is compulsary here 
    QuantMatrix(const  std::vector<std::vector<double>>& prices) : prices(prices){std::cout << "Copied\n";};

    // move constructer
    QuantMatrix( std::vector<std::vector<double>>&& prices) : prices(std::move(prices)){std::cout << "Moved\n";};
};
std::vector<std::vector<double>> loadMatrix()
{
    std::vector<std::vector<double>>prices(10000 , std::vector<double>(10000,0));
    for(size_t i = 0; i < 10000; i++)
    {
        for(size_t j = 0; j < 10000; j++)
        {
            prices[i][j] = 1000;
        }
    }
    return prices;
}
int main()
{
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = std::move(a);  // b steals memory, a is now empty

    std::vector<double> raw = {100.0, 101.0, 102.0};
    TickData tickcopy(raw);            // Triggers copy => copy construter copy kar diya to kaam nahi chal paiga 
    TickData tickmoved(std::move(raw)); // Triggers move => jab move constructer ko comment kar diya to copy constructer se kaam cha gya


    /*✅ 3. Practice Tasks
    Try these one by one:
    Create a class QuantMatrix that wraps a std::vector<std::vector<double>>.
    Add a constructor to accept data by copy and another by move.
    Write a function to loadMatrix() that returns a big matrix. Move it into your class.
    After moving, prsize_toriginal matrix size. What do you see?
*/
    std::vector<std::vector<double>> prices = loadMatrix();

    QuantMatrix copy(prices);
    QuantMatrix move(std::move(prices));
    
    return 0;
}