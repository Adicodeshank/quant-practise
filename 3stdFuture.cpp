#include <iostream>
#include <future>
#include <vector>
#include <string>
#include <chrono>
#include <random>

// Simulate a strategy running in the background
int run_strategy(const std::string& name, int seed) {
    std::mt19937 rng(seed); // Deterministic randomness per strategy
    std::uniform_int_distribution<int> dist(1000, 5000); // Simulate processing time
    std::uniform_real_distribution<double> pnl_dist(-5000.0, 10000.0); // Simulate PnL

    int work_time = dist(rng);
    std::this_thread::sleep_for(std::chrono::milliseconds(work_time));

    double pnl = pnl_dist(rng);
    std::cout << "[" << name << "] finished after " << work_time 
              << " ms with PnL: " << pnl << "\n";

    return static_cast<int>(pnl);
}

int main() {
    std::vector<std::future<int>> futures;

    // Strategy names and seeds for reproducibility
    std::vector<std::pair<std::string, int>> strategies = {
        {"Mean Reversion", 1},
        {"Momentum", 2},
        {"Stat Arb", 3}
    };

    std::cout << "Launching backtests...\n";

    // Launch all strategies asynchronously
    for (auto& strat : strategies) {
        futures.push_back(std::async(std::launch::async, run_strategy, strat.first, strat.second));
    }

    // Collect results
    double total_pnl = 0;
    for (auto& fut : futures) {
        total_pnl += fut.get(); // Waits for each strategy to complete
    }

    std::cout << "Total aggregated PnL: " << total_pnl << "\n";

    return 0;
}


// seed 
/* Why Do We Use a Seed?
There are two major reasons:

1. 🔬 Deterministic Reproducibility (most important for Quant)
If you give the same seed, the RNG will always produce the same sequence of numbers.

std::mt19937 rng(42);
std::uniform_int_distribution<int> dist(1, 10);
std::cout << dist(rng); // Always gives same output when seed is 42
✅ This is critical in quant/finance:

You want repeatable backtests

So results don't change every time you run

Makes debugging and comparison of strategies possible

2. 🧪 Controlled Randomness
Without a seed:
std::mt19937 rng(std::random_device{}()); // random seed each time
This gives you true pseudo-random behavior

But it's not reproducible

Good for things like shuffling, randomness in games

🧠 How Seeding Works in Practice
Example:
std::mt19937 rng(123); // Use fixed seed
std::uniform_int_distribution<int> dist(1, 10);

for (int i = 0; i < 5; ++i)
    std::cout << dist(rng) << " ";
Every time you run this, you'll get the same output:
7 4 9 6 1
Change the seed to 124, and you'll get a completely different sequence.*/