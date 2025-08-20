K = int(input()); S = input(); n = len(S)
#Ngoặc đúng: 1 mở phải kẹp 1 đóng --> Lẻ thì sai luôn. Độ sâu lớn nhất có thể cũng không thể vượt quá n/2 được
if n % 2 == 1 or K > n // 2:
    print(0)
    exit()
# Độ cao b: Số dấu ngoặc mở ra, nhưng chưa được đóng tại thời điểm đó
# dp0[b]: Số cách đi đến ở độ cao b, CHƯA từng đạt K, dp1[b]: Số cách đi đến độ cao b, ĐÃ từng đạt K
dp0 = [0] * (K + 1); dp1 = [0] * (K + 1)
if K == 0: dp1[0] = 1  # xâu rỗng đã có độ sâu tối đa 0. Xâu đúng: Chẳng có xâu nào độ sâu là 0 cả, trừ xâu rỗng thôi
else: dp0[0] = 1
for ch in S:
    #ndp0, ndp1: Trạng thái sau khi add ký tự đang xét
    #Gặp dấu đóng thì b - 1 thôi. 
    # Dead case: )((??))(. Vào một phát mà gặp ngay dấu mở, thì nb = -1, thế thì khỏi xét nữa, làm gì có dấu ngoặc nào trước mở đầu nữa đâu
    ndp0 = [0] * (K + 1); ndp1 = [0] * (K + 1)
    for b in range(K + 1):
        if dp0[b] == 0 and dp1[b] == 0: continue
        # Thử đặt '(' nếu được
        if ch in '?(':
            nb = b + 1
            if nb <= K: 
                # Sau khi thêm 1 dấu mở nữa thì độ cao đã đạt đủ là K = bậc của xâu đúng.
                # Nếu nb > K thì loại bỏ vì:
                #   1. Nếu không đóng ngoặc kịp => xâu ngoặc sai.
                #   2. Nếu có đóng ngoặc kịp => xâu hợp lệ nhưng độ sâu > K => không tính.
                if nb == K:  ndp1[nb] += dp0[b]; ndp1[nb] += dp1[b]
                # Độ cao đã là K. 
                else: ndp0[nb] += dp0[b]; ndp1[nb] += dp1[b]
        # Thử đặt ')' nếu được
        if ch in '?)':
            nb = b - 1
            if nb >= 0: ndp0[nb] += dp0[b]; ndp1[nb] += dp1[b]
    dp0, dp1 = ndp0, ndp1
print(dp1[0])
