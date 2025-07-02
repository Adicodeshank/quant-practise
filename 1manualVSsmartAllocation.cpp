#include<iostream>
#include<memory>
struct Signal {
    std::string name;
    Signal(std::string n) : name(std::move(n)) {}
    virtual double compute_score() const = 0;
    virtual ~Signal() = default;
};

// Derived Signal 1
struct Alpha1 : Signal {
    Alpha1() : Signal("Alpha1") {}
    double compute_score() const override {
        return 0.42;  // logic for alpha1
    }
};

// Derived Signal 2
struct Alpha2 : Signal {
    Alpha2() : Signal("Alpha2") {}
    double compute_score() const override {
        return 0.75;  // logic for alpha2
    }
};

// Derived Signal 3
struct Alpha3 : Signal {
    Alpha3() : Signal("Alpha3") {}
    double compute_score() const override {
        return 0.33;  // logic for alpha3
    }
};
int main()
{
    Alpha2* signal = new Alpha2();
    std::cout << signal->compute_score() << "\n";
    // simulate early return or exception
    delete signal;


    auto signal2 = std::make_unique<Alpha2>();
    std::cout << signal2->compute_score() << "\n";
    // nothing to delete, handled by destructor
}

//  memory 
/*| Metric              | Manual (`new/delete`) | Smart (`unique_ptr`)                          |
| ------------------- | --------------------- | --------------------------------------------- |
| Allocation location | Heap (via `new`)      | Heap (via `new` under the hood)               |
| Size (pointer)      | 8 bytes (raw pointer) | 8 bytes (smart pointer)                       |
| Ownership model     | You manage manually   | RAII (ownership tied to scope)                |
| Exception safety    | ❌ Risk of leak        | ✅ Auto-released                               |
| Performance         | Same allocation cost  | Slightly more code at compile time (template) |
*/