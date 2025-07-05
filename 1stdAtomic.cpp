// what is the problem 

#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>

std::atomic<int>counter;
int times = 100000;
// std::mutex mtx;

void run()
{
    for(int i = 0; i <= times; i++)
    {
        // withourt the atomic and lock counter will have inconsistent value 
        // use mutex lock but best is to make the vaiable atomic  
        counter++;
    }
}

int main()
{
    std::thread thread1(run);
    std::thread thread2(run);  // fixed name

    thread1.join();
    thread2.join();

    std::cout << counter << "\n";
    return 0;
}
