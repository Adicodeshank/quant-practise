/*💼 4. Mini-Project: Move-Optimized Order Intake
📦 You’ll build a simplified order intake system that:
Accepts large orders (vector of ticks)
Moves them into storage without copying
Shows how data lives in only one place at a time*/

#include<iostream>
#include<memory>
#include<utility>
#include<map>
#include<vector>
class Order {
public:
    int id;
    double price;
    int quantity;
    std::string side; // "BUY" or "SELL"

    Order(int id_, double price_, int qty_, const std::string& side_)
        : id(id_), price(price_), quantity(qty_), side(side_) {}
};
class OrderBook{
private:
    std::map<int, std::shared_ptr<Order>> orders;
public:
    void addOrder(std::shared_ptr<Order> order)
    {
        orders[order->id] = order;
    }

    void cancelOrder(int id) {
        orders.erase(id); // shared_ptr deleted if no other owners
    }

    std::shared_ptr<Order> getOrder (int id)
    {
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
    std::vector<std::weak_ptr<Order>> watchlist;
public:
    void watch(std::shared_ptr<Order> order)
    {
        watchlist.push_back(order);
    }

    void check() {
        for (auto& wptr : watchlist) {
            if (auto locked = wptr.lock()) {
                std::cout << "[Risk] Watching Order ID: " << locked->id << " Price: " << locked->price << "\n";
            } else {
                std::cout << "[Risk] Order expired (cancelled)\n";
            }
        }
    }
};

int main()
{
    std::shared_ptr<Order> order1 = std::make_shared<Order>(1, 100.5, 10, "BUY");
    std::shared_ptr<Order> order2 = std::make_shared<Order>(2, 101.0, 5, "SELL");

    RiskEngine engine;
    OrderBook order;

    order.addOrder(order1);
    order.addOrder(order2);

    engine.watch(order1);
    engine.watch(order2);

    std::cout << "== Orders Added ==\n";
    order.print();

    std::cout << "\n== Risk Check 1 ==\n";
    engine.check();

    order.cancelOrder(1); // erase order1

    std::cout << "\n== Risk Check 2 ==\n";
    engine.check();

    std::cout<<"1    "<<order.getOrder(1);
    std::cout<<"2    "<< order.getOrder(2);

    return 0;
}

