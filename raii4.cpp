#include <iostream>

class DoubleArray {
private:
    double* data;
    size_t size;
    /* ✅ Definition:
size_t is an unsigned integer type (only positive values) used to represent sizes or counts — like:

The size of an array

The number of elements in a container

Memory allocation size

It’s defined in the <cstddef> or <stddef.h> header, and used all over C/C++ standard libraries. 

size_t is more portable and safer than unsigned int for memory or size-related tasks.
*/

// size of array or memory will always be positive then why use int which can be negative 
// ====== ======= ex : size_t x = 10;  // same as: unsigned int x = 10; ================
// ======unsigned int is an integer type that can only store non-negative numbers (0 and up).
// It removes the ability to store negative values, and doubles the positive range.=============

public:
    // Constructor: allocate memory
    DoubleArray(size_t n) // this means unsigned int n 
    {
        size = n;
        data = new double[size];
        std::cout << "Allocated " << size * sizeof(double) << " bytes\n";
    }

    // Destructor: free memory
    ~DoubleArray() {
        delete[] data;
        std::cout << "Freed memory\n";
    }

    void set(size_t i, double value) {
        if (i < size) {
            data[i] = value;
        }
    }

    double get(size_t i) const {
        std :: cout << "how" <<"\n";
        return (i < size) ? data[i] : 0.0;
    }

    void printAll()  const 
    {
        // const =>  this method is safe to use even on read-only objects.”
        for (size_t i = 0; i < size; ++i) {
            std::cout << "data[" << i << "] = " << data[i] << "\n";
        }
    }
    void avg() {
        double add = 0;
        double avg = 0;
        for(size_t i = 0; i < size; i++)
        {
            add += data[i];
        }
        avg = add/size;
        std :: cout << "Average would be : " << avg <<"\n";
    }
};
int main() {
    {
        DoubleArray prices(5);  // RAII starts here

        prices.set(0, 100.25);
        prices.set(1, 101.10);
        prices.set(2, 102.50);
        prices.set(3, 99.85);
        prices.set(4, 100.75);

        prices.printAll();

        prices.avg();

    } // RAII ends here — automatic cleanup
}
