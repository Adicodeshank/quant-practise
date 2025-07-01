/*| Feature          | **Stack**                      | **Heap**                          |
| ---------------- | ------------------------------ | --------------------------------- |
| **Lifetime**     | Automatic (scope-based)        | Manual (`new`, `malloc`) or smart |
| **Speed**        | 🔥 Very Fast                   | 🐢 Slower (due to OS calls)       |
| **Size**         | Small (e.g. \~1MB–8MB default) | Large (limited by RAM)            |
| **Use Case**     | Temporary/local variables      | Large/complex/dynamic data        |
| **Cleanup**      | Automatic (RAII)               | Manual or smart pointer           |
| **Thread-safe?** | Yes                            | Must manage manually              |
*/