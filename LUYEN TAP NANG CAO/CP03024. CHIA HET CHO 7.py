for _ in range(int(input())):
    n = int(input())
    if n%7==0:
        print(n)
        continue
    cnt = 1000; check = 0
    while cnt:
        n+=int(str(n)[::-1])
        if n%7==0: 
            print(n)
            check = 1
            break 
    if check==0: print(-1)