// Try building this yourself (modify and experiment):
// Change the array size from 5 to 10.
// Add a for loop to set values.
// Print all 10 values.
// Add print messages to understand the flow.

#include <iostream>
class MyArray {
private :
    int* data;

public : 
    MyArray()
    {
        std:: cout << "constructer was called automatically as object is created\n";
        data = new int[10];
    }

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

int main()
{
    MyArray arr;
    for(int i = 0; i < 10; i++)
    {
        std:: cout << "setter\n";
        arr.set(i,i+1);
    }

    for(int i = 0; i < 10; i++)
    {
        std :: cout << "printing the using get\n";
        std :: cout << "value" << arr.get(i)<<"\n";
    }
}