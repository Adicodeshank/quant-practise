#include <iostream>

class MyArray {
private:
    int* data;

public:
    // Constructor: allocate memory
    MyArray() {
        data = new int[5];
        std::cout << "Memory allocated\n";
    }

    // Destructor: free memory
    ~MyArray() {
        delete[] data;
        std::cout << "Memory freed\n";
    }

    void set(int i, int value) {
        data[i] = value;
    }

    int get(int i) {
        return data[i];
    }
};

int main() {
    {
        MyArray arr;
        arr.set(0, 42);
        std::cout << "Value: " << arr.get(0) << "\n";
    } // <-- arr goes out of scope here, so memory is freed
}

/* "Memory allocated" is printed when MyArray is created.
"Memory freed" is printed when the object is destroyed automatically.*/
