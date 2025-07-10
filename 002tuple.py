# Plain Explanation:
# A tuple is an immutable, ordered collection of elements.

# Like a list, but you can’t change it (immutability = safer).

# It’s used to group related data — e.g., (symbol, price) or (timestamp, signal, volume).

tick = ("AAPL", 187.5)
symbol = tick[0]
price = tick[1]

symbol, price = tick
print(symbol, price)  # AAPL 187.5

# ⚠️ Tuples can contain mixed types — string, float, int, even lists.
trade = ("GOOG", "BUY", 100, 2812.0)
print(trade)

#####################
trades = [
    ("AAPL", "BUY", 100, 187.5),
    ("MSFT", "SELL", 50, 312.1),
    ("TSLA", "BUY", 30, 699.0)
]

for trade in trades:
    sym, side, qty, px = trade
    print(f"{side} {qty} shares of {sym} at ${px}")

###################
###########
# 🧠 5. Memory Analysis & Optimization
# Why is tuple smaller?
# Immutable = no dynamic resizing = smaller memory footprint.

# Python can optimize memory (e.g., caching small tuples).

# Safer in multithreading.
# Immutable = Cacheable = Fast:

"""| Situation                               | Use tuple? | Why?                  |
| --------------------------------------- | ---------- | --------------------- |
| Tick data `(symbol, price)`             | ✅          | Compact and fast      |
| Trade records                           | ✅          | Safer than list       |
| Key in hash map (`(symbol, timestamp)`) | ✅          | Hashable              |
| You need mutability or math ops         | ❌          | Use `list` or `numpy` |
"""
