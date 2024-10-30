#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16, INF = 1e18 + 7; 
int n, cost[MAXN][MAXN], dp[1 << MAXN][MAXN]; // dp[i][j] là chi phí nhỏ nhất để đạt được trạng thái i và kết thúc tại thành phố j

void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)cin >> cost[i][j];
    }
    for (int mask = 1; mask < (1 << n); mask++) { // Duyệt qua từng trạng thái
        if (__builtin_popcount(mask) > 1) {
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    int preMask = mask - (1 << i); 
                    dp[mask][i] = INF; 
                    for (int j = 0; j < n; j++) {
                        if ((preMask >> j) & 1) dp[mask][i] = min(dp[mask][i], dp[preMask][j] + cost[j][i]);
                    }
                }
            }
        }
    }
    int res = INF; 
    for (int i = 0; i < n; i++) res = min(res, dp[(1 << n) - 1][i]);
    cout << res << endl;
}

int main() {
    int t; 
    cin >> t; 
    while (t--) solve(); 
}
