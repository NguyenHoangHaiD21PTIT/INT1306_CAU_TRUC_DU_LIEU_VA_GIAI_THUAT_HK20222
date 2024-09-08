#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int, int>
const int N = 2e7+5, M = 1e3+5, MOD = 1e9+7, inf = 1e18;
int n, m, x, y, res, test, cnt, sum, k, hs;
int a[N], vt[N], t[N];

void v1() {
    res = 0;
    for (int i = 1; i <= n; ++i) vt[i] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        x = 0;
        for (int j = 1; j < a[i]; ++j) x += vt[j] == 0;
        res += x * t[n - i];
        vt[a[i]] = 1;
    }
    cout << res + 1 << endl;
}

void v2() {
    cin >> x;
    for (int i = 1; i <= n; ++i) vt[i] = 0;
    for (int i = n - 1; i > 0; --i) {
        if (x == 0) {
            for (int j = n; j > 0; --j) {
                if (!vt[j]) cout << j << ' ';
                vt[j] = 1;
            }
            break;
        }
        y = x / t[i]; cnt = 0;
        m = x;
        x -= y * t[i];
        //if (y == 0) y = 1;
        if (m % t[i] > 0) ++y;
        for (int j = 1; j <= n; ++j) {
            if (vt[j] == 0) ++cnt;
            if (cnt == y) {
                vt[j] = 1;
                cout << j << ' ';
                break;
            }
        }
    }
        for (int j = 1; j <= n; ++j)
            if (!vt[j]) cout << j;

    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> test;
    t[1] = 1;
    for (int i = 2; i <= 15; ++i) t[i] = t[i - 1] * i;
    while (test--) {
        cin >> n >> k;
        if (k == 1) v1(); else v2();
    }
}
