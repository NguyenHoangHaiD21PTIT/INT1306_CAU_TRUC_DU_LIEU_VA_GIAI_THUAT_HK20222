file = open("BANGNHAC.INP", "r")
a = []
for line in file:
    b = list(map(int, line.split()))
    for x in b: a.append(x)
n = a[0]
a.pop(0)
music = []
for i in range(n): music.append([i + 1, a[i]]) #Thêm vào id và thời gian phát
music.sort(key=lambda x: x[1])
tong = music[0][1]
out = open("BANGNHAC.OUT", "w")
for i in range(1, n): 
    music[i][1] +=music[i - 1][1]
    tong+=music[i][1]
for i in range(n): out.write(f"{music[i][0]} {music[i][1]}\n")
out.write(f"{tong}\n")
# http://chvoj.edu.vn/problem/python_bangnhac
