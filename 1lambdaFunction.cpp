// ========== Lambda Function =============
// 🧠 An unnamed, inline function you can pass or use on the spot.
//  lambda function can access any variable inside main through capture clause 
/*=============== Syntax ============ 
[ capture ] ( parameters ) -> return_type {
    // function body
};
🔹 [capture]: Which variables from outside the lambda you want to use
🔹 (parameters): Like any function — inputs
🔹 return_type: Usually optional; inferred
🔹 body: Your logic
*/

#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    int d = 3;
    int e = 9;
    std::cout<<"d is " << d <<"\n";
    auto add = [](int a , int b)
    {
        return a+b;
    };
    std::cout<<add(2,3) << "\n"; 
    /*[] = no capture
    (int a, int b) = input
    Returns a + b*/

    // ex2 
    std::vector<double> prices = {101.2, 99.5, 100.7};

    std::sort(prices.begin(), prices.end(), [](double a, double b) {
        return a < b; // Ascending
    });


    //ex3
    std::for_each(prices.begin(), prices.end(), [](double x){std::cout<<x<<"\n";});
    //ex4 => passing more than one variable inside lambda function 
    std::for_each(prices.begin(), prices.end(), [&d, &e](int x) {
        // d can be captured by lamda function 
        // d = 10; but d can't be changed in function if you take then by pass by value
        // id [&d] then you can change the value of d inside lamda function
        d = 5;
        if(x%d==0)
        {
            std::cout<<x<< "is divisible by " << d << "\n";
        }
        else
        {
            std::cout<<x<< "is not divisible by " << d << "\n";
        }
        
        std::cout<<"d is changed inside lambda function " << d <<"\n";
    });
    std::cout<<"d is changed inside lambda function but printing outside lambda function" << d <<"\n";// it will the value of d outside the lambda function 


    //ex4 => capturing all variable by (pass by refernce)
    std::for_each(prices.begin(), prices.end(), [&](int x) {
        // for capturing all values by ===== PASS BY VALUE ======  => [=]
        d = 5;
        if(x%d==0)
        {
            std::cout<<x<< "is divisible by " << d << "\n";
        }
        else
        {
            std::cout<<x<< "is not divisible by " << d << "\n";
        }
        
        std::cout<<"d is changed inside lambda function " << d <<"\n";
    });
    std::cout<<"d is changed inside lambda function but printing outside lambda function" << d <<"\n";


    // task 1 
    // Filter out prices greater than 100 from this vector
    std::vector<double> a = {99.0, 101.2, 100.5, 98.7};
    std::for_each(a.begin(), a.end(), [](int x){
        if(x>100.0)
        {
            std::cout<<x << "is greater than 100 "<< "\n";
        }
    });


}