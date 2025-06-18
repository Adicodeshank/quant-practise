// ============================== memory-optimized order book ====================================================

#include<iostream>
#include<memory>
#include<map>
#include<vector>
/*🚀 Project Goal
You're building a mini Order Book system that:
Holds orders in memory efficiently (using shared_ptr)
Allows a Risk Engine to watch orders (using weak_ptr) without owning them
Demonstrates smart pointer lifecycle (object creation, observation, deletion)
*/

class Order {
public:
    int id;
    double price;
    int quantity;
    std::string side; // "BUY" or "SELL"

    Order(int id_, double price_, int qty_, const std::string& side_)
        : id(id_), price(price_), quantity(qty_), side(side_) {}
};

class OrderBook {
private:
    std::map<int, std::shared_ptr<Order>> orders; 

public:
    void addOrder(std::shared_ptr<Order> order) {
        orders[order->id] = order;
    }

    void cancelOrder(int id) {
        orders.erase(id); // shared_ptr deleted if no other owners
    }

    std::shared_ptr<Order> getOrder(int id) {
        return orders.count(id) ? orders[id] : nullptr;
    }

    void print() {
        for (const auto& pair1 : orders) {
        auto order = pair1.second;
        std::cout << order->side << " ID: " << order->id
                  << " Price: " << order->price
                  << " Qty: " << order->quantity << "\n";
    }
    }
};
class RiskEngine {
private:
    std::vector<std::weak_ptr<Order>> watchedOrders;

public:
    void watch(std::shared_ptr<Order> order) {
        watchedOrders.push_back(order); // weakly observe only 
    }

    void check() {
        for (auto& wptr : watchedOrders) {
            if (auto locked = wptr.lock()) {
                std::cout << "[Risk] Watching Order ID: " << locked->id << " Price: " << locked->price << "\n";
            } else {
                std::cout << "[Risk] Order expired (cancelled)\n";
            }
        }
    }
};
int main() {
    OrderBook book;
    RiskEngine risk;

    auto order1 = std::make_shared<Order>(1, 100.5, 10, "BUY");
    auto order2 = std::make_shared<Order>(2, 101.0, 5, "SELL");

    book.addOrder(order1);
    book.addOrder(order2);

    risk.watch(order1);
    risk.watch(order2);

    std::cout << "== Orders Added ==\n";
    book.print();

    std::cout << "\n== Risk Check 1 ==\n";
    risk.check();

    book.cancelOrder(1); // erase order1

    std::cout << "\n== Risk Check 2 ==\n";
    risk.check();
}
