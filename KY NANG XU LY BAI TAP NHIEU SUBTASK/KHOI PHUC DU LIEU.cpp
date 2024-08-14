#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int, int>
const int N = 1e5+5, M = 1e3, MOD = 1e9+7, inf = 1e18;
int n, m, x, y, res, test, cnt, sum, k, d;
int a[N], mx[M][M], ans[M][M], mxA[M][M], f[M][M];

void nhan(int a[M][M], int b[M][M], int m, int n_, int p) {
    int x[m + 1][p + 1];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j) {
            x[i][j] = 0;
            for (int k = 0; k < n_; ++k)
                x[i][j] = (x[i][j] + a[i][k] * b[k][j]) % MOD;
        }
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j) a[i][j] = x[i][j];
}

void sol() {
    for (int i = 0; i < k; ++i) mxA[i][i] = 1;
    int mu = n - 1;
    while (mu) {
        if (mu & 1) nhan(mxA, mx, k, k, k);
        nhan(mx, mx, k, k, k);
        mu /= 2;
    }
    nhan(ans, mxA, 1, k, k);
}

int powmod(int n, int k) {
    int ans = 1;
    while (k) {
        if (k & 1) ans = (ans * n) % MOD;
        n = (n * n) % MOD;
        k >>= 1;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        mx[i][(i + 1) % k] = 3;
        mx[i][(i + 2) % k] = 3;
        mx[i][(i + 0) % k] = 1;
    }
    if (k == 1) {
        ans[0][0] = 7; mx[0][0] = 7;
    }
    else if (k == 2) {
        ans[0][0] = 4; ans[0][1] = 3;
        mx[0][1] = 3; mx[0][0] = 4;
        mx[1][0] = 3; mx[1][1] = 4;
    }
    else {
        ans[0][0] = 1; ans[0][1] = 3; ans[0][2] = 3;
    }

    sol();
    cout << (ans[0][0] - 1 + MOD * MOD) % MOD;

}
