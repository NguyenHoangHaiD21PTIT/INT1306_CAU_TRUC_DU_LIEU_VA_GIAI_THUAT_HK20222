import math
for _ in range(int(input())):
    x = int(input())
    minRes = 10**201
    check = 0
    for a in range(0, 201):
        for b in range(0, 201):
            if (a + b >= 1) and (a + b <= 200):
                s = "8" * a + "6" * b
                if (int(s) % x == 0):
                    minRes = min(minRes, int(s))
                    check = 1
    if check==0: print(-1)
    else: print(minRes)