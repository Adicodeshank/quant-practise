#include<iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int counter = 0;

void increment ()
{
    for(size_t i = 0; i < 100; i++)
    {
        std::lock_guard<std::<mutex> lock(mtx); // Lock happens here
        ++counter;
    }// auto lock unlock ho jaiga 
}



int main()
{
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std :: cout << "counter" << counter << "/n"
}