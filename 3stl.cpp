#include<iostream>
#include<numeric>
#include<vector>
#include <functional> // for multiplies
#include <iomanip>    // for std::setprecision
class ReturnTracker {
    public:
    std::vector<double> daily_returns; // e.g., +0.01, -0.02 for +1%, -2%

    void add_return(double r) {
        daily_returns.push_back(r);
    }

    void print_returns() const {
        for (double r : daily_returns)
            std::cout << r << " ";
        std::cout << "\n";
    }

    void compute_cumulative_returns()
    {
        std::vector<double> gross_returns;
        for(double& r :  daily_returns)
        {
            gross_returns.push_back(r+1.0);
        }

        std::vector<double> cumulative_gross(gross_returns.size());
        std::partial_sum(
            gross_returns.begin(),
            gross_returns.end(),
            cumulative_gross.begin(),
            std::multiplies<>()
        );

        std::cout << "\nCumulative Returns:\n";
        for (double g : cumulative_gross) {
            std::cout << std::fixed << std::setprecision(4) << (g - 1.0) << " ";
            // fixed so that scientifix notation use na ho 
            // setprecision so that 4 ka round off mile 
        }
    }
};
int main()
{
    ReturnTracker rt;
    rt.add_return(0.01);   // +1%
    rt.add_return(-0.005); // -0.5%
    rt.add_return(0.007);  // +0.7%
    rt.add_return(-0.01);  // -1%

    std::cout << "Daily returns:\n";
    rt.print_returns();

    rt.compute_cumulative_returns();
}