#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1000][1000];

// Tính diện tích toàn phần của cột có chiều cao h nằm trong 1 ô vuông đơn vị
int area(int h) {
    if (h == 0) return 0;
    return h * 4 + 2;
}

// Tính phần diện tích xung quanh chung giữa cột có chiều cao hiện tại (chiều cao h) so với các cột kề nó trước đó
// Chỉ xét các cột bên trái và phía trên cột hiện tại
int inter(int i, int j, int h) {
    if (i == 0 && j == 0) return 0;
    if (i == 0) return min(h, arr[i][j-1]); // Những "cột" Hàng đầu tiên thì chỉ bị che bởi cột bên trái
    if (j == 0) return min(h, arr[i-1][j]); // Những "cột" Cột đầu tiên thì chỉ bị che bởi cột phía trên
    return min(h, arr[i][j-1]) + min(h, arr[i-1][j]);
}

// Tính tổng diện tích toàn phần của tất cả các cột trong ma trận arr
int calc() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int s = inter(i, j, arr[i][j]);
            ans += area(arr[i][j]) - s * 2;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> arr[i][j];
        }
        cout << calc() << endl;
    }
}
