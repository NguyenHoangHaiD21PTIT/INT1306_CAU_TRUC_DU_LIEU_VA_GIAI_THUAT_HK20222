#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
char a[505][505];
int dp[505][505], nxt[505][505]; //dp lưu kết quả k bước, nxt lưu kết quả tương lai
// dp[r1][r2]: số cách để người 1 đến hàng r1 và người 2 đến hàng r2 tại bước thứ k

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    if (a[1][1] != a[n][n]) {
        cout << 0;
        return 0;
    }
    dp[1][n] = 1;
    // Duyệt k từ 0 đến n - 2 (tổng n -1 bước để gặp nhau ở giữa). k là số bước đã đi
    for (int k = 0; k < n - 1; ++k) {
        memset(nxt, 0, sizeof(nxt)); 
        for (int r1 = 1; r1 <= n; ++r1) {
            for (int r2 = 1; r2 <= n; ++r2) {
                if (!dp[r1][r2]) continue;
                // Cứ đi 1 bước thì hoặc r tăng 1 (xuống) hoặc c tăng 1 (phải). Ví dụ, ban đầu r1 = c1 = 1. Tổng là 2. Đi k bước thì tổng tăng thêm k
                // r1 + c1 = k + 2, r2 + c2 = 2n - k 
                int c1 = k + 2 - r1, c2 = 2 * n - k - r2;
                if (c1 < 1 || c1 > n || c2 < 1 || c2 > n) continue;
                // 1. P1 Xuống, P2 Lên
                if (r1 + 1 <= n && r2 - 1 >= 1 && a[r1 + 1][c1] == a[r2 - 1][c2]) nxt[r1 + 1][r2 - 1] = (nxt[r1 + 1][r2 - 1] + dp[r1][r2]) % MOD;
                // 2. P1 Xuống, P2 Trái
                if (r1 + 1 <= n && c2 - 1 >= 1 && a[r1 + 1][c1] == a[r2][c2 - 1]) nxt[r1 + 1][r2] = (nxt[r1 + 1][r2] + dp[r1][r2]) % MOD;
                // 3. P1 Phải, P2 Lên
                if (c1 + 1 <= n && r2 - 1 >= 1 && a[r1][c1 + 1] == a[r2 - 1][c2]) nxt[r1][r2 - 1] = (nxt[r1][r2 - 1] + dp[r1][r2]) % MOD;
                // 4. P1 Phải, P2 Trái
                if (c1 + 1 <= n && c2 - 1 >= 1 && a[r1][c1 + 1] == a[r2][c2 - 1]) nxt[r1][r2] = (nxt[r1][r2] + dp[r1][r2]) % MOD;
            }
        }
        memcpy(dp, nxt, sizeof(nxt));
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans = (ans + dp[i][i]) % MOD;
    cout << ans;
}