
#include <bits/stdc++.h>
using namespace std;

const int oo = 1e18 + 7;
int n, a[16][16], f[1 << 16][16];

void solve() {
    memset(f, 0, sizeof(f));
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> a[i][j];

    int x = 1 << n;
    for (int mask = 1; mask < x; ++mask) {
        if (__builtin_popcount(mask) > 1) {
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    int pre_mask = mask ^ (1 << i);
                    f[mask][i] = oo;
                    for (int j = 0; j < n; ++j) {
                        if ((pre_mask >> j) & 1) {
                            f[mask][i] = min(f[mask][i], f[pre_mask][j] + a[j][i]);
                        }
                    }
                }
            }
        }
    }

    int res = oo;
    for (int i = 0; i < n; ++i) res = min(res, f[x - 1][i]);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int TC; cin >> TC;
    while (TC--) solve();
}
