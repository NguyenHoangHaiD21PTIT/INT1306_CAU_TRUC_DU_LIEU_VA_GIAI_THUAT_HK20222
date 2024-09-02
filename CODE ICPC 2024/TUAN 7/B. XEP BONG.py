import math
B = [0] * 1001
B[0] = 1
def Bell():
    for i in range(1, 50):
        B[i] = 0
        for j in range(i): B[i] += math.comb(i - 1, j) * B[j]
Bell()
t = int(input())
for _ in range(t):
    n = int(input())
    print(B[n])