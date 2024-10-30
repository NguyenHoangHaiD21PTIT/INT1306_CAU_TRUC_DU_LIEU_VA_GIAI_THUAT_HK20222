#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ii pair<int, int>
#define x first
#define y second
const int N = 1e5+5, M = 1e3+5, inf = 1e18, MOD = 1e9+7;
int n, m, x, y, res, k, cnt, sum, test;
int a[N], b[N], ans[2][6], mx[6][6], mxA[6][6];

void mul(int a[6][6], int b[6][6], int m, int n, int p) {
    int x[m + 1][p + 1];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= p; ++j) {
            x[i][j] = 0;
            for (int k = 1; k <= n; ++k) x[i][j] = (x[i][j] + a[i][k] * b[k][j]) % MOD;
        }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= p; ++j) a[i][j] = x[i][j];
}

void mul_matrix() {
    if (n < 4) {
        cout << n << endl;
        return;
    }
    memset(mxA, 0, sizeof mxA);
    memset(mx, 0, sizeof mx);

    mx[2][1] = mx[3][2] = mx[3][3] = mx[5][3] = mx[4][4] = mx[5][5] = mx[5][4] = 1;
    mx[1][2] = mx[4][3] = mx[4][2] = mx[5][2] = 2; mx[2][2] = 3;

    ans[1][1] = 2; ans[1][2] = 3; ans[1][3] = 9; ans[1][4] = 3; ans[1][5] = 1;
    for (int i = 1; i <= 6; ++i) mxA[i][i] = 1;
    n -= 3;
    while (n) {
        if (n & 1) mul(mxA, mx, 5, 5, 5);
        n >>= 1;
        mul(mx, mx, 5, 5, 5);
    }
    mul(ans, mxA, 1, 5, 5);
    cout << ans[1][2] << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> test;
    while (test--) {
        cin >> n;
        mul_matrix();
    }
}
