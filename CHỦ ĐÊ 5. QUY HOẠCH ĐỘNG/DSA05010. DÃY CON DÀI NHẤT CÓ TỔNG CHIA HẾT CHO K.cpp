#include <bits/stdc++.h>
using namespace std;
int dp[1005][55]; //dp[i][j]: Độ dài dãy con dài nhất từ a[0..i-1] có tổng % k = j
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            int r = a[i - 1] % k; 
            for (int j = 0; j < k; j++) {
                dp[i][j] = dp[i - 1][j]; 
                int j1 = (j - r + k) % k; //j1 + r = j
                if (dp[i - 1][j1] > 0 || j1 == 0) dp[i][j] = max(dp[i][j], dp[i - 1][j1] + 1);
            }
        }
        cout << dp[n][0] << "\n";
    }
}
