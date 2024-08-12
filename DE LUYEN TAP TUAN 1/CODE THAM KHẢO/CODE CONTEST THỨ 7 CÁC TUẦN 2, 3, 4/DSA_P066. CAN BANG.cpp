#include <bits/stdc++.h>
using namespace std;

int a[12], all_sum = 0, s[4];//s[i]: Khối lượng góc thứ i
bool un[12];//un[i] = true: người thứ i đã có chỗ ngồi

int Try(int g, int ind, int sum, int pre) {
    //g: chỉ số nhóm, ind: số người hiện tại trong nhóm, sum: tổng khối lượng hiện có của nhóm
    //pre: chỉ số bắt đầu chọn: Tức là chỉ chọn từ người thứ bao nhiêu đổ đi
    int ans = INT_MAX;
    if (g == 3) { //Chia xong 3 góc thì suy ra được góc thứ 4
        s[3] = all_sum - s[0] - s[1] - s[2];
        // Tìm giá trị lớn nhất và nhỏ nhất trong 4 góc
        int MAX = s[0];
        int MIN = s[0];
        for (int i = 1; i < 4; i++) {
            if (s[i] > MAX) MAX = s[i];
            if (s[i] < MIN) MIN = s[i];
        }
        return min(ans, MAX - MIN);
    }
    for (int i = pre; i < 12; i++) {
        if (un[i]) { // Kiểm tra xem người chơi thứ i đã được chọn chưa
            un[i] = false; // Đánh dấu người chơi thứ i đã được chọn
            if (ind == 2) { // Khi nhóm hiện tại đã có đủ 3 người
                s[g] = sum + a[i]; // Cập nhật tổng khối lượng của nhóm hiện tại
                ans = min(ans, Try(g + 1, 0, 0, 0)); // Chuyển sang nhóm tiếp theo
            } else { // Nếu nhóm hiện tại chưa đủ 3 người
                ans = min(ans, Try(g, ind + 1, sum + a[i], i + 1)); // Tiếp tục thêm người vào nhóm hiện tại
            }
            un[i] = true; // Đánh dấu lại người chơi thứ i chưa được chọn để có thể dùng cho các nhóm khác
        }
    }
    return ans;
}

int main() {
    for (int i = 0; i < 12; i++) cin >> a[i];
    for (int i = 0; i < 12; i++) all_sum += a[i];
    for (int i = 0; i < 12; i++) un[i] = true;
    cout<< Try(0, 0, 0, 0)<<endl;
}