import math
for _ in range(int(input())):
    m = int(input())
    res = []
    res.append((m, 1))  
    res.append((m, m - 1))  
    for k in range(2, 51):
        l = 2 * k
        r = int((pow(m, 1.0 / k) + 1) * k)
        n = -1
        while l <= r:
            mid = (l + r) // 2
            try: val = math.comb(mid, k)  
            except ValueError: val = 0  
            if val == m:
                n = mid  
                break
            elif val < m: l = mid + 1  
            else: r = mid - 1  
        if n != -1:
            res.append((n, k))
            res.append((n, n - k))
    res = sorted(set(res))
    print(len(res))
    for x in res: print("({},{})".format(x[0], x[1]), end = ' ')
    print()
