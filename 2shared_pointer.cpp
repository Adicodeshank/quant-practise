#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> a = std::make_shared<int>(42); // ref count = 1
    std::shared_ptr<int> b = a;                         // ref count = 2
    {
        std::shared_ptr<int> c = a;                     // ref count = 3
        std::cout << "Use count (inside): " << c.use_count() << "\n";
    } // c is destroyed, ref count = 2

    std::cout << "Use count (outside): " << a.use_count() << "\n";
} // a and b destroyed, ref count = 0 → memory freed

// With reference count:
// C++ automatically deletes the object when no one is using it anymore — no memory leaks, no double free.

/*
std::shared_ptr<int> a = std::make_shared<int>(42);
             |
             V
     ┌──────────────────────────┐
     │  Pointer to `int(42)`    │
     │  Ref count: 1            │
     │  Weak count: 0           │
     └──────────────────────────┘

*/
// when you copy it 
/*  
    std::shared_ptr<int> b = a;
             |
             V
     ┌──────────────────────────┐
     │  Pointer to `int(42)`    │
     │  Ref count: 2            │
     │  Weak count: 0           │
     └──────────────────────────┘

*/