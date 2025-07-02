#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <iomanip>
///////////////////////  READ CODE DOUBTS HA ISME //////////////////////////////
// Base class for all signals
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

int main() {
    std::vector<std::unique_ptr<Signal>> registry;

    // Add signals to registry
    registry.push_back(std::make_unique<Alpha1>());
    registry.push_back(std::make_unique<Alpha2>());
    registry.push_back(std::make_unique<Alpha3>());

    // Print all signal scores
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Registered Signals and Their Scores:\n";
    for (const auto& signal : registry) {
        std::cout << signal->name << ": " << signal->compute_score() << "\n";
    }

    return 0;  // All memory cleaned up automatically
}
