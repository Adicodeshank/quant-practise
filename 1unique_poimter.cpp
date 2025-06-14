#include <memory>
#include <iostream>
#include<vector>
// why unique pointer
// 🧠 5. Memory Insight
// What?	            Where?	   Size
// double[] array	    Heap	5 × 8 bytes = 40 bytes
// unique_ptr itself	Stack	8 bytes (just the pointer)
// Automatically deallocated when the PriceSeries object is destroyed.
int main() {
    std::unique_ptr<int> x = std::make_unique<int>(42);  // create int(42) on heap
    /*
        What Happens Here?
        std::make_unique<int>(42) allocates memory on the heap for an integer and sets its value to 42.

        It returns a smart pointer — std::unique_ptr<int> — which takes ownership of the memory.

        So now, x is a pointer to a heap-allocated int with value 42.

        ⛑️ You do not need to call delete — x will automatically free memory when it goes out of scope.
    */
    std::cout << *x << "\n";  // prints: 42

    // How to work with array 
    std::unique_ptr<double[]>prices = std::make_unique<double[]>(5);
    // prices is a heap memory pointing to double array when array goes out of scope unique_ptr automatically free memory 
    for(size_t i = 0; i < 5; i++)
    {
        prices[i] = 100.0 + i;
    }
    for(size_t i = 0; i < 5 ;i++)
    {
        std::cout<<prices[i]<<" ";
    }

    // handling with vector
    std::unique_ptr<std::vector<double>> prices2 = std::make_unique<std::vector<double>>(5); // here 5 is size of vector
    // but we do not need vector with uniqur_ptr beacuse vector behind the scene work with heap instead we need <vector T>
    (*prices2)[0] = 100.5;
    (*prices2)[1] = 101.2;
    (*prices2)[2] = 99.8;
    (*prices2)[3] = 98.7;
    (*prices2)[4] = 102.1;

    // Print values
    for (double price : *prices2) {
        std::cout << "Price: " << price << "\n";
    }


    // copying the pointer 
    std::unique_ptr<int> a = std::make_unique<int>(5);
    // can not copy pointers like this 
    // std::unique_ptr<int>b = a; => throw an error 

    std::unique_ptr<int>b = std::move(a); // okay to tranfer ownership 

}