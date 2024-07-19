file = open("VIEC.INP", "r")

#1. Đọc dữ liệu
a = []
for line in file:
    b = list(map(int, line.split()))
    for x in b: a.append(x)
file.close()
n = a[0]
a.pop(0)

#2. Sắp xếp theo tiền thưởng giảm dần
task = []
for i in range(n): task.append([i, a[2 * i], a[2 * i + 1]])
task.sort(key = lambda x: -x[2])
print(task)

#3. Tìm deadline tối đa
max_deadline = max(task, key=lambda x: x[1])[1]
h = [-1] * (max_deadline + 1)  # -1: Chưa có việc được chọn, h[i] = j: Tại thời điểm i làm việc thứ j
chuaxep = []  # Những việc không xếp để hoàn thành đúng hạn được
tongThuong = 0

def timChoXep(v, x):  #4. Tìm chỗ xếp cho việc thứ v, có deadline là x
    for i in range(x, 0, -1):
        if h[i] == -1: return i
    return 0


sub = [0] * n
for i in range(n):
    j = timChoXep(task[i][0], task[i][1])
    if j > 0:
        h[j] = task[i][0]
        tongThuong += task[i][2]
    else:
        chuaxep.append(task[i][0])

m = 0 #Số lượng sau khi dồn
for i in range(1, max_deadline + 1):
    if h[i]!=-1:
        h[m] = h[i]
        h[i] = -1
        m+=1
for v in chuaxep: h[m] = v;  m += 1  
out = open("VIEC.OUT", "w")      
for i in range(m): out.write(f"{h[i] + 1}\n")
out.write(f"{tongThuong}")
out.close()
#http://chvoj.edu.vn/problem/python_xepviec
