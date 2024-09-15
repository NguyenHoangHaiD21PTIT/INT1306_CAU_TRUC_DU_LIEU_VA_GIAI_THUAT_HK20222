#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int,int>
const int N = 1e6+5, M = 1e3+1, inf = 1e18, MOD = 1e9+7;
int test, n, m, x, y, res, k, cnt1, sum;
int a[N], t[N], f[20][20][2];

int dp(int i, int gh, int cnt, int ko) {
    if (i < 0) return ko;
    if (gh == 0 && f[i][cnt][ko] != -1) return f[i][cnt][ko];
    int ghm = (gh ? a[i] : 9), kq = 0;
    for (int j = 0; j <= ghm; ++j)
        if (!ko || abs(j - cnt) <= 1) kq += dp(i - 1, gh && j == ghm, j, ko | (j > 0));
    if (gh == 0) f[i][cnt][ko] = kq;
    return kq;
}

int get(int n) {
    int d = -1;
    memset(f, -1, sizeof(f));
    while (n) a[++d] = n % 10, n /= 10;
    return dp(d, 1, -1, 0);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int d = 1, c = inf;
    while (d <= c) {
        int mid = (d + c) >> 1;
        if (get(mid) >= n) res = mid, c = mid - 1;
        else d = mid + 1;
    }
//    if (n == 0) cout << 0;
//    else cout << (n == 1 ? 1 : res + 1);
    cout << res;
}

