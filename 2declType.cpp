#include<iostream>
double getPrice() { return 100.25; }
int getVolume() { return 300; }
int main()
{
    // double notional = getPrice() * getVolume();
    //  sometimes the value of price and volume when get multiplied then becomes int or float but you carry them as double means taking extra memory hence use this 
    decltype(getPrice()*getVolume()) notional3 = getPrice()*getVolume();
    // task 2 
    float price = 99.99f;
    int volume = 200;

    decltype(price * volume) notional2 = price * volume;

    std::cout << "Notional: " << notional2 << " | Size: " << sizeof(notional2) << "\n";
    std::cout<<sizeof(int);

    // float price = 99.99f;
    // int volume = 200;

    decltype(price * volume) notional = price * volume;

    std::cout << "Type size of notional: " << sizeof(notional) << " bytes\n";

    

}