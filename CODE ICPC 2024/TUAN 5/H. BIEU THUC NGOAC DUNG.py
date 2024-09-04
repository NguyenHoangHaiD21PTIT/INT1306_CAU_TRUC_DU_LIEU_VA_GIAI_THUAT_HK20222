for _ in range(int(input())):
    n, k = map(int, input().split())
    f = [[[0 for _ in range(2)] for _ in range(k + 1)] for _ in range(n + 1)]
    #f[i][j][c]: Số biểu thức ngoặc đúng còn lại i ký tự chưa xử lý (trên tổng số n ký tự cần thêm), j dấu mở ngoặc chưa có dấu đóng tương ứng
    #c: Cờ đánh dấu biểu thức ấy đã đạt đến bậc k chưa (c = 1 là đã đến, c = 0 thì chưa)
    f[n][0][0] = 1 #Chuỗi rỗng, chỉ có 1 cách tạo duy nhất
    for x in range(n, 0, -1):
        for y in range(k, -1, -1):
            for c in range(2):
                if y > 0: f[x-1][y-1][c] += f[x][y][c] #Thêm một ngoặc đóng
                if y < k: #Thêm một ngoặc mở
                    if y + 1 == k: f[x-1][y+1][1] += f[x][y][c]  # Nếu y+1 == k, thì bậc đã đạt k, cập nhật cờ thành 1.
                    else: f[x-1][y+1][c] += f[x][y][c]  # Nếu y+1 < k, cờ vẫn giữ nguyên.
    result = f[0][0][1]
    a = str(result)
    if len(a) > 10: print(f"{a[:5]}...{a[-5:]}")
    else: print(a)
