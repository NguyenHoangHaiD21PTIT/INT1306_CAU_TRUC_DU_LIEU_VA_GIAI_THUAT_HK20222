#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
int n, q;
long long a[MAXN], dp[MAXN][MAXN];  // dp[L][R] = số bộ ba trong đoạn [L..R]
unordered_map<long long,int> cnt;
long long g[MAXN], pre[MAXN];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int r = 1; r <= n; r++) {
        if (r < 3) continue;
        cnt.clear();
        for (int i = r - 1; i >= 1; --i) {
            long long need = -(a[i] + a[r]);
            g[i] = cnt[need];  
            cnt[a[i]]++;
        }
        pre[0] = 0;
        for (int i = 1; i <= r - 2; i++) pre[i] = pre[i - 1] + g[i];
        long long total = pre[r-2];
        for (int l = 1; l <= r - 2; l++) dp[l][r] = dp[l][r-1] + (total - pre[l-1]);
    }
    while (q--) {
        int l, r; cin >> l >> r;
        if (r - l + 1 < 3) cout << 0 << "\n";
        else cout << dp[l][r] << "\n";
    }
}
//Partial Accepted: 8/16 (TLE) (Pass Sub1, Sub2)
