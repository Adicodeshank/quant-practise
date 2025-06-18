#include<iostream>
#include<utility>
#include<vector>
#include<utility>
std::vector<double> getPrices() {
    std::vector<double> data = {101.5, 102.0, 99.8};
    return data;  // C++ will auto-move here => this is internally using std::move not making a copy of data vector and then returning it , it is transferring the ownership of data vector
}

std::vector<int> loadLargeVector(){
    std::vector<int>a(10000);
    for (int i = 0; i < 10000; ++i) {
        a[i] = i;
    }
    return a;
}
int main()
{
    std::string a = "Quant";
    std::string b = a; // Both `a` and `b` hold "Quant" 

    /*But what if the object is large (e.g. big vector)? Copying is slow and memory-expensive.
    👉 Enter move semantics:
    It transfers ownership of resources instead of duplicating them.
    ================ After move, the source is empty or reset (but still valid).===========*/

    std::vector<int>original = {1, 2, 3};
    std::cout<<"1st" << "\n";
    for(auto it : original)
    {
        std::cout<<it<<" ";
    }
    std::cout<<"\n";

    std::vector<int> moved = std::move(original);

    std::cout << "moved size: " << moved.size() << "\n";       // 3
    std::cout << "original size: " << original.size() << "\n"; // 0
    for(auto it : moved)
    {
        std::cout<<it<<" ";
    }
    std::cout<<"\n";
    /* original ka 0 ho gya and moved ka size 3 ho gya ownership transfer ki then source is empty */

    // ============== But we can still use original ====================================
    original.push_back(4);
    std::cout<<"After push back in original" <<"\n" ;
    std::cout << "moved size: " << moved.size() << "\n";       //  ========== still 3 ===========
    std::cout << "original size: " << original.size() << "\n"; // ============ now 1 =======
    for(auto it : original)
    {
        std::cout<<it<<" ";
        // moved mein std::move() karne ke baad ke ele(jo original mein push hue ) nahi jainge
    }
    std::cout<<"\n";
    for(auto it : moved)
    {
        std::cout<<it<<" ";
    }
    std::cout<<"\n";

    std::vector<double> price = getPrices(); // data array ki ownership aati ha 

    /*🔹 Task 2:
    Write a function std::vector<int> loadLargeVector() that returns a large vector (10,000 ints).
    Call it and move the result into a variable.
    Print the vector size.*/

    std::vector<int>passing  =  (loadLargeVector());
    std::cout<<"size inside main without move " << passing.size() << "\n";

    std::vector<int> bigVector = std::move(loadLargeVector());  
    std::cout<<"size inside main wiht move " << passing.size() << "\n";

}