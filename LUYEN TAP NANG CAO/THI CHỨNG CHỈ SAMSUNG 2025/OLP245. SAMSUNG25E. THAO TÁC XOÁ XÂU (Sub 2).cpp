#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, dp[N][N];
char s[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    // Trường hợp cơ sở:
    for (int i = 0; i < n; i++) dp[i][i] = 1;   // Xóa 1 ký tự tốn 1 thao tác
    for (int i = 0; i < n; i++) dp[i][i - 1] = 0; // dp[l][r] = 0 nếu l > r (xâu rỗng)
    // Quy hoạch động theo độ dài đoạn
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            // Lựa chọn 1: Xóa s[l] riêng lẻ
            dp[l][r] = 1 + dp[l + 1][r];
            // Lựa chọn 2: Ghép s[l] với một s[k]
            for (int k = l + 1; k <= r; k++) {
                if (s[k] == s[l]) dp[l][r] = min(dp[l][r], dp[l + 1][k - 1] + dp[k][r]);
            }
        }
    }
    cout << dp[0][n-1];
}
