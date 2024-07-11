n, m = map(int, input().split())
a = list(map(int, input().split()))
tich1 = 1
res = []
for x in a: tich1*=x
for i in range(m):
    b = list(map(int, input().split()))
    tich2 = 1
    for y in b: tich2*=y
    if tich1%tich2==0: res.append(i + 1)
print(len(res))
for x in res: print(x, end = " ")