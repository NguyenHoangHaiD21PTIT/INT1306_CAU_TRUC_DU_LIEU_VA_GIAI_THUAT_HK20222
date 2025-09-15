#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll w[16][16]; 
int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++) {
            ll x;
            cin >> x;
            w[i][j] = w[j][i] = x;
        }
    }
    int lim = 1 << n;
    ll dp[1 << 16] = {}; 
    ll ans = 0;
    for (int m = 0; m < lim; m++) {
        int i;
        //Tìm đỉnh đầu tiên chưa có trong tập
        for (i = 0; i < n; i++){
            if (!(m & (1 << i))) break;
        }
        if (i == n) {
            ans = max(ans, dp[m]);
            continue;
        }
        for (int j = i + 1; j < n; j++){
            if (!(m & (1 << j))) {
                int nm = m | (1 << i) | (1 << j);
                dp[nm] = max(dp[nm], dp[m] + w[i][j]);
                ans = max(ans, dp[nm]);
            }
        }
    }
    cout << ans;
}
