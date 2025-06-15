// ✅ Task 1:
// Create a shared_ptr<int> that 3 different variables point to. Modify the value from each, and print it.

#include<iostream>
#include<memory>

int main()
{
    std::shared_ptr<int> a = std::make_shared<int>(23);
    std::shared_ptr<int> c = a;   
    std::shared_ptr<int> b = a;   
    std::shared_ptr<int> d =  a;

    std::cout<< *a; // they are pointer pointing at int 23 and *a will go the the address pointed by a print the 23
    std::cout<< *b;
    std::cout<< *c;
    std::cout<< *d;
    // a b c d poins to same memory location 

    b = std::make_shared<int>(44);
    c = std::make_shared<int>(42);
    // b c points to 44  c points to 42 d still points to 23

    // *c = *b; // now c points to b

    std::shared_ptr<int> e = std::make_shared<int>(42);
    std::shared_ptr<int> f = std::make_shared<int>(*e);  // creates new memory with same value

    *e= 99; // e changes its value 

    std::cout << *e << "\n"; // 99
    std::cout << *f << "\n"; // 42
    

}