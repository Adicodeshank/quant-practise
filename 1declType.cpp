    #include<iostream>
    double getPrice() 
    {
        return 101.25; 
    }
    int main()
    {
        int x = 10;
        decltype(x)  y = 23;
        //decltype does not evaluate the expression — it only looks at the type.
        int z= 2;
        decltype(z+2.55) w = 23;
        // now w is a type of double bacause z+2.55 is double 
        int shares = 100;
        double price = 245.75;
        decltype(shares * price) notional = shares * price;
        std::cout << "Notional value = " << notional << std::endl;
        std::cout<<"Type of notional2 " << sizeof(notional) << "\n";
        //====>>>So notional is of type double — (========== decided at compile time by the compiler ===========) using decltype.
        float share2 = 100;
        int price2 = 245;
        decltype(share2 * price2) notional2 = share2 * price2;
        std::cout << "Notional value = " << notional << std::endl;
        std::cout<<"Type of notional2 " << sizeof(notional2) << "\n";

        // ============================//
        decltype(getPrice()) lastprice = getPrice();// lastPrice is double => lastprice will carry the type returned by function

        // =================================================
        float notionalF = 1000000.25f;
        double notionalD = 1000000.25;
        long double notionalLD = 1000000.25L;

        std::cout << "Size of float: " << sizeof(notionalF) << "\n";
        std::cout << "Size of double: " << sizeof(notionalD) << "\n";
        std::cout << "Size of long double: " << sizeof(notionalLD) << "\n";

    }