#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9999;
int main() {
    int n;
    cin >> n;
    vector<int> L, R;
    L.push_back(0); R.push_back(0); 
    int rMax = 0;
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        L.push_back(l); R.push_back(r);
        rMax = max(rMax, r);
    }
    int ans = 0;
    for (int v = 1; v <= rMax; v++) {
        int fv = 1, fv1 = 1;
        for (int i = 1; i <= n; i++) {
            fv = (1LL * fv * max(0, min(R[i], v) - L[i] + 1)) % MOD;
            fv1 = (1LL * fv1 * max(0, min(R[i], v - 1) - L[i] + 1)) % MOD;
        }
        ans = (ans + 1LL * v * ((fv - fv1 + MOD) % MOD)) % MOD;
    }
    cout << ans;
}
