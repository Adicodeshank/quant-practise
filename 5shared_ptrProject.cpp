#include <iostream>
#include <memory>
#include <vector>

class PriceFeed {
private:
    std::vector<double> prices;
public:
    PriceFeed(std::vector<double> p) : prices(std::move(p)) {}
    void print() const {
        for (auto price : prices)
            std::cout << price << " ";
        std::cout << "\n";
    }
};

class SignalGenerator {
public:
    SignalGenerator(std::shared_ptr<PriceFeed> pf) : feed(pf) {}
    void run() {
        std::cout << "SignalGen: ";
        feed->print();
    }
private:
    std::shared_ptr<PriceFeed> feed;
};

class RiskManager {
public:
    RiskManager(std::shared_ptr<PriceFeed> pf) : feed(pf) {}
    void check() {
        std::cout << "RiskMgr: ";
        feed->print();
    }
private:
    std::shared_ptr<PriceFeed> feed;
};

int main() {
    auto sharedFeed = std::make_shared<PriceFeed>(std::vector<double>{101.5, 102.0, 99.8});

    SignalGenerator sg(sharedFeed);
    RiskManager rm(sharedFeed);

    sg.run();
    rm.check();

    std::cout << "Use count: " << sharedFeed.use_count() << "\n";  // 3 (main + sg + rm)
}
