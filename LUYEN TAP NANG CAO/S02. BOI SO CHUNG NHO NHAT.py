from math import gcd
from sys import stdin

def lcm(x, y):
    return abs(x * y) // gcd(x, y)

a = []
for line in stdin: a.append(int(line.strip()))
n = a[0]
for i in range(1, 2 * n, 2): print(lcm(a[i], a[i + 1]))
