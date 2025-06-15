//=================== vector<T>=======================
// --------------ex 1 -------------------------
#include <iostream>
#include <vector>

// A templated container that holds any type T
template <typename T>
class DataStore {
private:
    std::vector<T> data;

public:
    void add(const T& value) {
        data.push_back(value);  // Add element to vector
    }

    void printAll() const {
        for (const T& val : data) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    size_t size() const {
        return data.size();
    }

    const T& get(size_t index) const {
        return data.at(index); // safer than []
    }
};

int main() {
    // Integers
    DataStore<int> intStore;
    intStore.add(10);
    intStore.add(20);
    intStore.add(30);
    intStore.printAll();  

    // Doubles
    DataStore<double> priceStore;
    priceStore.add(100.5);
    priceStore.add(101.2);
    priceStore.printAll();  

    // Strings
    DataStore<std::string> nameStore;
    nameStore.add("AAPL");
    nameStore.add("GOOG");
    nameStore.add("MSFT");
    nameStore.printAll();  
}

// ============= =============== ex-2 =======================
