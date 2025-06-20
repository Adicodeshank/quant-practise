// ==================== closures =====================

/*🎯 Step 1: What Are Closures?
👶 Basic Intuition:
A closure is a lambda function that can remember variables from its surrounding scope.
Think of a closure as a little function + memory bundle.*/

#include<iostream>
int main()
{
    int x = 3;
    auto closure = [x](int y){
        return x+y;
    } ;
    int add=closure(3);
    std::cout<<add<<"\n";

    double priceLimit = 105.0;
    auto isAcceptable = [&priceLimit](double price) {
        priceLimit = 22;
        return price > priceLimit;
    };

    bool task2 = isAcceptable(23);

    std::cout<<task2<<"\n";

    





};
