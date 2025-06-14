// A mini quant backtest engine is a small program that simulates how a trading strategy would have performed in the past, using historical market data.

/*
Backtesting = running your strategy back in time to:

1)See if it would’ve made profit or losses

2)Evaluate its risk

3)Optimize performance
*/

// 🧩 What is inside a "mini backtest engine"?
// Component	  ->      What It Does
// 🗃️ Data loader -> 	Reads price data from CSV or API
// 📈 Strategy logic	-> Example: Buy if price > moving average
// 🎯 Signal execution	-> Simulates "buy" or "sell" at each step
// 💰 Portfolio tracker -> 	Tracks P&L (profit/loss), positions, capital
// 📊 Stats engine -> 	Calculates metrics: return, drawdown, Sharpe ratio, etc.
// 🧪 Testing environment->	Runs over many assets or parameter values (multi-threaded!)


// 🧱 Example: What Would a Mini Backtester Do?
/* // Let's say you want to test this simple strategy:

// Buy Apple stock when price goes above its 5-day average. Sell when it goes below.

// A mini backtest engine would:

// Load Apple's price history

// Loop through each day

// At each day:

// Check your rule

// Simulate a "buy" or "sell"

// Track your cash, shares, P&L

// At the end, print stats like:

// Total return

// Number of trades

// Max drawdown

// Sharpe ratio */

#include<iostream>
#include<fstream>
#include<thread>
#include<mutex>
#include<vector>
#include<stdio.h>
#include<climits>
#include<utility>

// std::mutex mtx;

class miniBacktest {
private:
    std::vector<double>data;
    bool intPosition = false; // means mere pass stocks ha ya nahi => false mtlb nahi ha 
public:
    miniBacktest (size_t n) : data(n)
    {

    }

    std::vector<double> ReadData(const std::string& fileName)
    {
        std::ifstream fileIn(fileName);
        double value;
        size_t i = 0;
        while(fileIn >> value && i < data.size())
        {
            data[i++] = value;
        }

        return data;
    }

    double calculateAverage(const std::vector<double>& data)
    {
        double add = 0;
        for(size_t i = 0; i < data.size(); i++)
        {
            add+=data[i];
        }
        return add/data.size();
    }

    std::pair<double,double> calculateMinMax(const std::vector<double>& data)
    {
        double maxi = INT_MIN;
        double mini = INT_MAX;
        for(size_t i = 0; i < data.size(); i++)
        {
            if(data[i] < mini)
            {
                mini = data[i];
            }
        }
        for(size_t i = 0; i < data.size(); i++)
        {
            if(data[i] > maxi)
            {
                maxi = data[i];
            }
        }


        return {mini,maxi};
    }

   // simulator
   /*
    🧱 Basic Terms You Need
        Cash: Your starting capital (e.g., ₹1000)

        Shares: How many stocks you own

        Price: The price of the stock on each day

        In Position: Are you currently holding a stock?
   */

   void simulator(std:: vector<double> & prices)
   {
        double cash = 1000.0;
        double shares = 0;
        for(double price : prices)
        {
            if(!intPosition && price>100.9 )
            {
                std::cout << "BUY at " << price << "\n";
                shares = cash/price;
                cash = 0;
                intPosition = true;
            }
            else if(intPosition && price < 100.0)
            {
                std::cout << "SELL at " << price << "\n";
                cash = shares*price;
                shares = 0;
                intPosition = false;
            }
        }

        double finalValue = cash + (shares * data.back());
        std::cout << "Final Portfolio Value: " << finalValue << "\n";  
   }
};

int main()
{
    miniBacktest obj(5);

    std::vector<double> data = obj.ReadData("prices.csv");
    std::cout<<"prices ";
    for(size_t i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";

    double avg = obj.calculateAverage(data);
    std::cout << "Avg :" << avg << "\n";
    
    std::pair<double,double>minMax = obj.calculateMinMax(data);
    std::cout<< "mini " << minMax.first << " maxi ," << minMax.second;
    std::cout << "\n";
    
    obj.simulator(data);
}
// reseach on project
// one standard deviation
//  