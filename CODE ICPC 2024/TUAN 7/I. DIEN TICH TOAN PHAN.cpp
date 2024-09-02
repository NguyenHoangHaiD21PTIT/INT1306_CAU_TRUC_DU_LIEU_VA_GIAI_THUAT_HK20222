#include <bits/stdc++.h>
using namespace std;

// Tính diện tích toàn phần của cột có chiều cao h nằm trong 1 ô vuông đơn vị
int area(int h) {
    if (h == 0) return 0;
    return h * 4 + 2;
}

// Tính phần diện tích xung quanh chung giữa cột có chiều cao arr[i][j] và cột có chiều cao h
// Chỉ xét các cột bên trái và phía trên cột hiện tại
int inter(int i, int j, int h, const vector<vector<int>>& arr) {
    if (i == 0 && j == 0) return 0;
    if (i == 0) return min(h, arr[i][j-1]); // Hàng đầu tiên thì chỉ bị che bởi cột bên trái
    if (j == 0) return min(h, arr[i-1][j]); // Cột đầu tiên thì chỉ bị che bởi cột phía trên
    return min(h, arr[i][j-1]) + min(h, arr[i-1][j]);
}

// Tính tổng diện tích toàn phần của tất cả các cột trong ma trận arr
int calc(int n, int m, const vector<vector<int>>& arr) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int s = inter(i, j, arr[i][j], arr);
            ans += area(arr[i][j]) - s * 2;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> arr[i][j];
        }
        cout << calc(n, m, arr) << endl;
    }
}
