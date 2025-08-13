#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 6005;
const int MOD = 1e9 + 7;

 // Hàm kiểm tra: có tồn tại hình vuông cạnh s (s = k*edge) có <= e ô tô màu?
bool ok(int s, int n, int m, int e, int t[6005][6005]) {
    if (s <= 0 || s > n || s > m) return false;
    for (int i = s; i <= n; ++i) {
        // end: i, len: s = en - st + 1 = i - st + 1 --> st = i - s + 1
        int i0 = i - s;
        for (int j = s; j <= m; ++j) {
            int j0 = j - s;
            int sum = t[i][j] - t[i0][j] - t[i][j0] + t[i0][j0];
            if (sum <= e) return true; 
        }
    }
    return false; 
}

int main() {
    int n, m, k, edge, e; //n: chiều ngang, m: chiều dọc, k: c ô vuông đã tô màu, edge: Cạnh hình vuông phải chia hết cho edge, e: số ô được tô màu tối đa
    cin >> n >> m >> k >> edge >> e;
    int a[6005][6005], t[6005][6005];
    for (int i = 1; i <= k; ++i) {
        int x, y; cin >> x >> y;
        a[x][y] = 1;
    }
    //Prefix sum 2D
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)  t[i][j] = t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1] + a[i][j];
    }
    // Nhị phân trên k (cạnh s = k*edge) k * edge <= min(n, m)
    int loK = 0, hiK = min(n, m) / edge, ans = 0;
    while (loK <= hiK) {
        int midK = (loK + hiK) / 2;
        int s = midK * edge;
        if (ok(s, n, m, e, t)) {
            ans = s; 
            loK = midK + 1; 
        } else {
            hiK = midK - 1; 
        }
    }
    cout << ans;
}
