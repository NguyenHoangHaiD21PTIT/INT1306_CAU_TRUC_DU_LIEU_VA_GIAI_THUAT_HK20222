#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = -1e9, MAXN = 22; // Kích thước ma trận tối đa
int n, t, a[MAXN][MAXN]; // Ma trận và kích thước
int dp[21][1 << 20]; // Mảng dp

signed main() {
    cin >> t; 
    while (t--) { 
        cin >> n;
        for (int i = 1; i <= n; i++) {  
            for (int j = 0; j < n; j++) cin >> a[i][j]; 
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (1 << n); j++) dp[i][j] = 0;
        }
        for (int i = 0; i < n; ++i) dp[1][1 << i] = a[1][i];
        for (int i = 1; i < n; i++) {  // Xét đến hàng thứ i
            for (int state = 0; state < (1 << n); state++) { // Xét mọi trạng thái hàng trước đó
                if (dp[i][state]) { // Kiểm tra trạng thái hợp lệ
                    for (int j = 0; j < n; j++) { // Lần lượt bật từng bit hàng đang xét lên
                        if ((state & (1 << j)) == 0) { // Nếu cột j chưa được chọn ở hàng trước
                            int new_state = state | (1 << j); 
                            dp[i + 1][new_state] = max(dp[i + 1][new_state], dp[i][state] + a[i + 1][j]); 
                        }
                    }
                }
            }
        }
        cout << dp[n][(1 << n) - 1] << '\n'; 
    }
}
