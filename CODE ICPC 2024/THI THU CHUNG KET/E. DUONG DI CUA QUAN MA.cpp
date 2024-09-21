#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int, int>
const int N = 2e5+5, M = 1e3+5, MOD = 1e9+7, inf = 1e18;
int n, m, x, y, res, test, cnt, sum, k;
int a[N], mx[M][M], ans[M][M], mxA[M][M];
int xr[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int yr[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int nhan_an_do(int a, int b) {
    int ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return ans;
}

void nhan(int a[M][M], int b[M][M], int m, int n_, int p) {
    int x[m + 1][p + 1];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= p; ++j) {
            x[i][j] = 0;
            for (int k = 1; k <= n_; ++k)
                x[i][j] = (x[i][j] + nhan_an_do(a[i][k] , b[k][j])) % MOD;
        }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= p; ++j) a[i][j] = x[i][j];
}

void sol() {
    for (int i = 1; i <= 65; ++i) mxA[i][i] = 1;
    for (int i = 1; i <= 8; ++i)
        for (int j = 1; j <= 8; ++j)
            for (int e = 0; e < 8; ++e) {
                x = i + xr[e]; y = j + yr[e];
                if (x > 0 && y > 0 && x <= 8 && y <= 8) mx[(i - 1) * 8 + j][(x - 1) * 8 + y] = 1;
            }
    for (int i = 1; i <= 65; ++i) mx[i][65] = 1;
    k = n + 1; n = 65;
    while (k) {
        if (k & 1) nhan(mxA, mx, n, n, n);
        nhan(mx, mx, n, n, n);
        k /= 2;
    }
    ans[1][1] = 1;
    nhan(ans, mxA, 1, n, n);
    cout << ans[1][65];
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    sol();
}
