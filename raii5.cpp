#include <iostream>
#include <fstream>   // For file I/O
#include <string>
#include<vector>

class DoubleArray {
private:
    // int* data;
    std::vector<double> data;
    // size_t size;

public:
    DoubleArray(size_t n) : data(n)
    {
        
    }

    // ~DoubleArray() {
    //     delete data;
    // }

    void set(size_t i, double value) {
        if (i < data.size()) data[i] = value;
    }

    double get(size_t i) const {
        return (i < data.size()) ? data[i] : 0.0;
    }

    void printAll() const {
        for (size_t i = 0; i < data.size(); ++i)
            std::cout << "data[" << i << "] = " << data[i] << "\n";
    }

    double avg() const {
        double sum = 0;
        for (size_t i = 0; i < data.size(); ++i)
            sum += data[i];
        return sum / data.size();
    }

    void loadFromFile(const std :: string& fileName)
    {
        std :: ifstream infile(fileName);
        // ifstram is like a object and infile is like a variable 
        /*int is a type for integers,
        double is a type for decimals,
        std::string is a type for text/strings,
        👉 std::ifstream is a type for file input streams — i.e., a tool for reading from files.
        */

        double value;
        size_t i = 0;
        
        while(infile >> value && i < data.size())
        {
            data[i++] = value;
        }
        // infile >> value means => cin >> x this is same on is reading from keyboard other reading from file 

        infile.close();
    }

    void saveToFIle(std :: string fileName) const 
    {   
        std::ofstream outfile(fileName);
        //ofstream => out of stream 
        for (size_t i = 0; i < data.size(); ++i)
            outfile << data[i] << "\n";

        outfile << "Average: " << avg() << "\n";
        outfile.close();
    }
};

int main ()
{
    DoubleArray prices(5);

    prices.loadFromFile("prices.txt");

    prices.printAll();

    std::cout << "Average = " << prices.avg() << "\n";

    prices.saveToFIle("output.txt");
}
