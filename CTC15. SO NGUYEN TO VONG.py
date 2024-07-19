MN = 1000000 
P10 = [1, 10, 100, 1000, 10000, 100000, 1000000]  # 10^i, i = 0..6
# Các chữ số xấu: 0, 2, 4, 5, 6, 8
BADDIG = [1, 0, 1, 0, 1, 1, 1, 0, 1, 0]
b = bytearray([1] * MN)

# Sàng các số nguyên tố < MN
def ByteSieve():
    global b    
    b[0] = b[1] = 0
    for i in range(4, MN, 2): 
        b[i] = 0  # xóa các số chẵn 4..MN
    for i in range(3, int(MN ** 0.5) + 1, 2):
        if b[i]:  # xóa các bội (i*i, MN, i)
            for j in range(i * i, MN, i): 
                b[j] = 0    

# Quay x len-1 lần đều cho số nguyên tố
def AllRot1(x):
    n = len(str(x))
    head = P10[n - 1]  # 10^(n-1)
    # quay n-1 lần
    for i in range(1, n):
        c = x % 10  # chữ số thứ i
        if BADDIG[c]: 
            return 0
        # quay
        x = head * c + (x // 10)
        if not b[x]: 
            return 0
    return 1

# Đọc n từ file, ghi kq cũng ra file
with open("ROUNDPRI.INP", "r") as file:
    n = int(file.read().strip())

ByteSieve()

# Danh sách các số nguyên tố vòng tròn dưới 100
a = [2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97]

for i in range(101, MN, 2):
    if b[i] and AllRot1(i):
        a.append(i)

cnt = 0
for x in a:
    if x < n:
        cnt += 1

with open("ROUNDPRI.OUT", "w") as out:
    out.write(str(cnt))
#http://hoxuanhuong.edu.vn/problem/ctc15
