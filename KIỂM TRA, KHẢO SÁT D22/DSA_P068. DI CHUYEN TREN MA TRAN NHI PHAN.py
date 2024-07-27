n = int(input())
a = []
for i in range(n): a.append(list(map(int, input().split())))
for i in range(n):
    for j in range(n):
        if i == 0 and j != 0:
            a[i][j] = a[i][j - 1] * 2 + a[i][j]  # Hàng đầu tiên nhưng không phải cột đầu tiên
        elif i != 0 and j == 0:
            a[i][j] = a[i - 1][j] * 2 + a[i][j]  # Cột đầu tiên nhưng không phải hàng đầu tiên
        elif i != 0 and j != 0:
            a[i][j] = max(a[i - 1][j] * 2 + a[i][j], a[i][j - 1] * 2 + a[i][j])
print(str(hex(a[n - 1][n - 1]))[2::].upper())
