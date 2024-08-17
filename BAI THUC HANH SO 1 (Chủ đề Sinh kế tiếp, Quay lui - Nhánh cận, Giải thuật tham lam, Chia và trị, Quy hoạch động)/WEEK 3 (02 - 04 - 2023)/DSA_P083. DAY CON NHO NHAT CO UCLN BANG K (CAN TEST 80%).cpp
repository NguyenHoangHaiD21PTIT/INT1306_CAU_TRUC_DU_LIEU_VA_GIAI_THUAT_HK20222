#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int, int>
const int N = 2e5+5, M = 1e3+5, MOD = 1e9+9, inf = 1e18;
int n, m, x, y, res, test, sum1, k, d;
int a[N], t[N][18], vt[N], l[N], r[N];

int get(int l, int r) {
    int k = __lg(r - l + 1);
    return __gcd(t[l][k], t[r - (1 << k) + 1][k]);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> test;
    while (test--) {
        cin >> n >> k;
        res = n; y = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            t[i][0] = a[i];
        }
        int mask = __lg(n);
        for (int j = 1; j <= mask; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; ++i)
                t[i][j] = __gcd(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
        for (int i = 1; i <= n; ++i) if (a[i] % k == 0) {
            int d = 1, c = min(res, n - i + 1);
            while (d <= c) {
                int mid = (d + c) >> 1;
                x = get(i, i + mid - 1);
                if (x == k) {
                    ++y;
                    res = min(res, mid);
                    c = mid - 1;
                }
                else if (x < k) c = mid - 1;
                else d = mid + 1;
            }
        }
        cout << (y ? res : -1) << endl;
    }
}
