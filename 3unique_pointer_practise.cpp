#include<iostream>
#include<vector>
#include<memory>
#include<limits>
template <typename T>
class priceSeries {
private:
     std::unique_ptr<std::vector<T>> prices;
    size_t size;
public:
    priceSeries(size_t n)
        : size(n), prices(std::make_unique<std::vector<T>>(n)) {}

    void set(const size_t i,const  T val) {
        if (i < size) 
        {
           (*prices)[i] = val; 
        }
    }

    void print() const {
        for (size_t i = 0; i < size; ++i)
            std::cout << "Price[" << i << "] = " << (*prices)[i] << "\n";
    }

    T average() const {
        T sum = 0;
        for (size_t i = 0; i < size; ++i)
            sum += (*prices)[i];
        return sum / size;
    }

    T minCost()
    {
        T min = std::numeric_limits<T>::max();
        for (size_t i = 0; i < size; ++i)
            if ((*prices)[i] < min) min = (*prices)[i];
        return min;
    }

    T maxCost()
    {
        T max = std::numeric_limits<T>::min();
        for (size_t i = 0; i < size; ++i)
            if ((*prices)[i] > max) max = (*prices)[i];
        return max;
    }
};

int main() {
    priceSeries<double> series(5);
    series.set(0, 100.0);
    series.set(1, 101.5);
    series.set(2, 99.8);
    series.set(3, 102.3);
    series.set(4, 100.7);

    series.print();
    std::cout << "Avg: " << series.average() << "\n";
    std::cout << "Min: " << series.minCost() << "\n";
    std::cout << "Max: " << series.maxCost() << "\n";
     // Auto memory cleanup when 'series' goes out of scope
}

