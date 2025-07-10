# # In Simple Terms:
# # A list in Python is a resizable array that can hold anything — numbers, strings, objects — even other lists.

# # Think of it like std::vector in C++, but:

# # Dynamically typed (can mix types)

# # Resizable on the fly

# # Backed by a dynamic array under the hood

##############################################
#####################################
######################
# symbols = ['AAPL', 'MSFT', 'TSLA']
# pnl = [500, -200, 300]
# mixed = [True, 3.14, "Hello", None]

# print(mixed)

# # slicing
# print(pnl[0])   
# print(symbols[-1])  # 'TSLA' (last element)
# print(pnl[1:])     # [-200, 300]
# print(symbols[:2]) # ['AAPL', 'MSFT']

# # append
# pnl[0] = 999
# symbols.append('GOOG')
# del symbols[1]  # Remove 'MSFT'
#################################
#######################
###############

pnl = []
pnl.append(100)
pnl.append(-50)
pnl.append(200)
print("Total PnL:", sum(pnl))

pnl = [100, -50, 200, -30, 50]
positive_pnl = [x for x in pnl if x > 0]
print("Positive PnLs:", positive_pnl)

# sorting data 
trades = [("AAPL", 500), ("TSLA", -300), ("GOOG", 250)]
sorted_trades = sorted(trades, key=lambda t: t[1], reverse=True)
print("Best to worst:", sorted_trades)

###############################
#######################
##############

#memory optimization 
# Python lists are actually over-allocated arrays (like std::vector growth strategy).
# Python allocates extra space to avoid resizing on every append.
import sys
lst = []
for i in range(10):
    lst.append(i)
    print(f"Length: {len(lst)}, Size in bytes: {sys.getsizeof(lst)}")

# 📌 Note:

# Each .append() might not increase memory linearly

# Python over-allocates to amortize reallocation cost

# Downsides:
# list is not memory-tight

# For large datasets: consider numpy.array for compact storage

# ✅ In quant code:
# Use list for input, flexible data collection
# Then convert to numpy for speed
