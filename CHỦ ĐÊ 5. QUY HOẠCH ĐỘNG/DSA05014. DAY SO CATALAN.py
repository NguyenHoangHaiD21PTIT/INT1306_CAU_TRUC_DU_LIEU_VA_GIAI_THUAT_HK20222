C = [0] * 200
C[0] = 1; C[1] = 1
for i in range(2, 102):
    for j in range(0, i): C[i]+=C[j] * C[i - j - 1]

for _ in range(int(input())):
    n = int(input())
    print(C[n])