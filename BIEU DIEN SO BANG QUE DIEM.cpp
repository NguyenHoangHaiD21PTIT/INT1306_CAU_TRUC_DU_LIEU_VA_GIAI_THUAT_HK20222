#include <bits/stdc++.h>
using namespace std;

// Số que diêm cần thiết để tạo ra các chữ số từ 0 đến 9
vector<int> soQue = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; 

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);

    for (int i = 0; i < m; i++) cin >> a[i]; // Đọc các chữ số được sử dụng
    sort(a.begin(), a.end(), greater<int>()); // Sắp xếp các chữ số theo thứ tự giảm dần

    vector<int> dp(n + 1, -1); // Khởi tạo mảng dp để lưu số lượng chữ số tối đa có thể tạo được
    dp[0] = 0; // Với 0 que diêm, số chữ số tối đa là 0

    // Tính số chữ số tối đa có thể tạo ra với số lượng que diêm từ 1 đến n
    for (int i = 1; i <= n; i++) {
        for (int x : a) {
            int queDiem = soQue[x];
            if (i >= queDiem && dp[i - queDiem] != -1) {
                dp[i] = max(dp[i], 1 + dp[i - queDiem]);
            }
        }
    }

    // Xây dựng số lớn nhất có thể tạo ra
    string ketQua = "";
    int soQueConLai = n;

    while (soQueConLai > 0) {
        for (int x : a) {
            int queDiem = soQue[x];
            if (soQueConLai >= queDiem && dp[soQueConLai] == 1 + dp[soQueConLai - queDiem]) {
                ketQua += to_string(x);
                soQueConLai -= queDiem;
                break;
            }
        }
    }

    cout << ketQua << endl;
    return 0;
}
