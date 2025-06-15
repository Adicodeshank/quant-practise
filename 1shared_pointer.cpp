// Imagine you and your friends all love the same toy. Instead of each buying a new one, you all share the same toy — but no one throws it away until all of you are done playing.
/*
//That’s what std::shared_ptr does.
// It's a smart pointer that keeps a reference count.

// When you copy a shared_ptr, it doesn’t copy the object, it shares it.

// When the last shared_ptr is destroyed, the object gets deleted.

// ======= Memory cleanup is automatic and shared. =========
*/

/*
unique_ptr vs shared_ptr
Feature	     unique_ptr	     shared_ptr
Ownership	Sole owner	    Multiple owners
Copyable	❌ No	          ✅ Yes
Overhead	🚀 Very low	    🐢 Slightly higher
Use case	Local, RAII	     Shared resources
*/
#include<iostream>
#include<memory>
class MarketData {
private:
    double price;
public:
    MarketData(double p) : price(p) {
        std::cout << "MarketData created\n";
    }
    ~MarketData() {
        std::cout << "MarketData destroyed\n";
    }
    void show() const {
        std::cout << "Price: " << price << "\n";
    }
};
int main()
{
    std::shared_ptr<MarketData> data1 = std::make_shared<MarketData>(1222.2);
    // new MarketData(1222.2) => C++ internally allocates memory on the heap for this object.

    {
        std::shared_ptr<MarketData> data2 = data1; // sharing ownership
        data2->show(); //data2 is a pointer isiliye aise use kar sakte hai 
        std::cout << "Use count: " << data2.use_count() << "\n"; 
    }// data2 goes out of scope, but object is not deleted
    // data2 scope se bahar ho gya fir bhi deconstructer call nahi hua kykoi MarketData is shared with data1 also 

      std::cout << "Use count: " << data1.use_count() << "\n"; // 1
}// here object will get deleted 

