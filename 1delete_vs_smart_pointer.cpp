#include<iostream>
int main()
{
    // Task 1: Migrate new/delete to unique_ptr
    double* prices = new double[100];
    // ... use it
    delete[] prices;

    // To this:
    // auto prices = std::make_unique<double[]>(100);



}

/*memory
| Code                         | Memory Location               | Size             |
| ---------------------------- | ----------------------------- | ---------------- |
| `int x = 5;`                 | Stack                         | 4 bytes          |
| `int* p = new int(5);`       | Heap                          | 4 bytes          |
| `std::unique_ptr<int>`       | Stack (ptr) + heap (int)      | \~12 bytes total |
| `shared_ptr<double>` (1 ref) | Heap (object + control block) | 8 + \~16 bytes   |

*/