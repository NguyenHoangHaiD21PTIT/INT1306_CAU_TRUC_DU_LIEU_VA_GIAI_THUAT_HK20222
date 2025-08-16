#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
    int N, M; cin >> N >> M;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) cin >> L[i] >> R[i];
    vector<int> mu(M + 1, 1), prime;
    vector<int> lp(M + 1, 0);
    mu[0] = 0;
    for (int i = 2; i <= M; i++) {
        if (lp[i] == 0) { lp[i] = i; prime.push_back(i); mu[i] = -1; }
        for (int p : prime) {
            if (p > lp[i] || 1LL * p * i > M) break;
            lp[p * i] = p;
            if (p == lp[i]) mu[p * i] = 0;
            else mu[p * i] = -mu[i];
        }
    }
    long long ans = 0;
    vector<int> Lp(N), Rp(N);
    for (int d = 1; d <= M; d++) {
        if (mu[d] == 0) continue;
        int maxSum = M / d;
        bool ok = true;
        for (int i = 0; i < N; i++) {
            Lp[i] = (L[i] + d - 1) / d;
            Rp[i] = R[i] / d;
            if (Lp[i] > Rp[i]) { ok = false; break; }
        }
        if (!ok) continue;
        vector<int> dp(maxSum + 1, 0), pref(maxSum + 2, 0);
        dp[0] = 1;
        for (int i = 0; i < N; i++) {
            fill(pref.begin(), pref.end(), 0);
            for (int s = 0; s <= maxSum; s++) {
                pref[s + 1] = (pref[s] + dp[s]) % MOD;
            }
            vector<int> ndp(maxSum + 1, 0);
            for (int s = 0; s <= maxSum; s++) {
                int lo = s - Rp[i], hi = s - Lp[i];
                if (hi < 0) continue;
                lo = max(lo, 0);
                hi = min(hi, maxSum);
                if (lo <= hi) {
                    ndp[s] = (pref[hi + 1] - pref[lo] + MOD) % MOD;
                }
            }
            dp.swap(ndp);
        }
        long long ways = 0;
        for (int s = 0; s <= maxSum; s++) ways = (ways + dp[s]) % MOD;
        ans = (ans + mu[d] * ways) % MOD;
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << "\n";
}