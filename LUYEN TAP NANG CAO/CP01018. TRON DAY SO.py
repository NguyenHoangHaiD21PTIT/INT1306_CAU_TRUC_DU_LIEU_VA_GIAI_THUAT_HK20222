import math
for _ in range(int(input())):
    n, m = map(int, input().split())
    if n < m: n, m = m, n  
    tong = 0
    for i in range(m + 1): tong = (tong + math.comb(n-1, i) * math.comb(m+1, i+1)) % (10**9 + 7)
    print(tong)
