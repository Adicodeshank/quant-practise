/*| Feature          | **Stack**                      | **Heap**                          |
| ---------------- | ------------------------------ | --------------------------------- |
| **Lifetime**     | Automatic (scope-based)        | Manual (`new`, `malloc`) or smart |
| **Speed**        | 🔥 Very Fast                   | 🐢 Slower (due to OS calls)       |
| **Size**         | Small (e.g. \~1MB–8MB default) | Large (limited by RAM)            |
| **Use Case**     | Temporary/local variables      | Large/complex/dynamic data        |
| **Cleanup**      | Automatic (RAII)               | Manual or smart pointer           |
| **Thread-safe?** | Yes                            | Must manage manually              |
*/

#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    // int x = 42;                 // on stack
    // double prices[100];         // 800 bytes, on stack

    // int* p = new int(42);           // allocated on heap
    // std::vector<double>* v = new std::vector<double>(1000);  // heap
    // delete p;                       // manual cleanup
    // delete v;

    // auto v = std::make_unique<std::vector<double>>(1000);
    // auto cleanup 

    int x = 10;                     // stack
    int* y = new int(20);           // heap

    std::cout << "x: " << x << ", address: " << &x << "\n";
    std::cout << "y: " << *y << ", address: " << y << "\n";


    // allocate big memory 
    // int data[1000000];      // ❌ stack overflow
    // int* data = new int[1000000];  // ✅ heap



}
/*memory
| Code                           | Where is it stored?           | Approx. Size |
| ------------------------------ | ----------------------------- | ------------ |
| `int x = 5;`                   | Stack                         | 4 bytes      |
| `std::vector<int> v(1000);`    | Vector on stack, data on heap | \~4 KB       |
| `std::string s = "alpha";`     | Stack + heap (SSO varies)     | \~5–32 bytes |
| `auto ptr = new double[1000];` | Heap                          | \~8 KB       |

*/

/*| Learn This                   | Tip                                     |
| ---------------------------- | --------------------------------------- |
| Stack = fast but limited     | Use for scalars, small arrays           |
| Heap = flexible but risky    | Use smart pointers to manage safely     |
| STL uses heap internally     | `std::vector`, `std::map`, etc.         |
| Never `new` without `delete` | Or use `std::make_unique`, `shared_ptr` |
| For Quant, test under load   | Ensure no leaks, crashes, or slowness   |
*/