#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int, int>
const int N = 1e6+5, M = 1e3+5, MOD = 1e9+7, inf = 1e18;
int n, m, x, y, res, test, cnt1, sum, k, maxn = 1 << 19, block;
int a[N], ans[N], t[N], cnt[N];

int hilbert(int x, int y) {
    int d = 0;
    for (int s = 1 << 19; s; s >>= 1) {
        bool rx = x & s, ry = y & s;
        d = d << 2 | rx * 3 ^ static_cast<int>(ry);
        if (!ry) {
            if (rx) {
                x = maxn - x; y = maxn - y;
            }
            swap(x, y);
        }
    }
    return d;
}

struct node{
    int l, r, id, ord;
} b[N];

bool cmp(node a, node b) {
    return a.ord < b.ord;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].l >> b[i].r;
        b[i].id = i;
        b[i].ord = hilbert(b[i].l, b[i].r);
    }
    sort(b + 1, b + m + 1, cmp);
    int L = 0, R = 0;
    for (int i = 1; i <= m; ++i) {
        while (L < b[i].l) {
            if (L > 0) {
                --cnt[a[L]];
                if (cnt[a[L]] == 0) --res;
            }
            ++L;
        }
        while (L > b[i].l) {
            --L;
            ++cnt[a[L]];
            if (cnt[a[L]] == 1) ++res;
        }
        while (R < b[i].r) {
            ++R;
            ++cnt[a[R]];
            if (cnt[a[R]] == 1) ++res;
        }
        while (R > b[i].r) {
            --cnt[a[R]];
            if (cnt[a[R]] == 0) --res;
            --R;
        }
        ans[b[i].id] = res;
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << endl;
}
