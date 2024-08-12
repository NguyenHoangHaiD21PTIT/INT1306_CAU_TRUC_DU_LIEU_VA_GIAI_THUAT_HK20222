#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9;
const int MAXN = 1001;

int n, m, k;
int a[MAXN], b[MAXN];
int dp[11][MAXN][MAXN];
int pre[11][MAXN][MAXN];

void solve() {
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= m; l++) {
                if (a[j] > b[l]) {
                    if (i == 1) {
                        dp[i][j][l] = 1;
                    } else {
                        dp[i][j][l] = pre[i - 1][j - 1][l - 1];
                    }
                }
                pre[i][j][l] = (pre[i][j - 1][l] + dp[i][j][l]) % MOD;
                if (i == k) {
                    ans = (ans + dp[i][j][l]) % MOD;
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= m; l++) {
                pre[i][j][l] = (pre[i][j][l] + pre[i][j][l - 1]) % MOD;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + m + 1);
    solve();
}
