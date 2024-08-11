#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int, int>
const int N = 1e6+5, M = 1e3+5, MOD = 1e9+7, inf = 1e18;
int n, m, x, y, res1, test, cnt, sum;
int t[N], a1[N];
int res, f[M][M];

struct hcn{
    double x, y, z;
} a[N];

struct tron{
    double r, h;
} b[N];

double max1(double a, double b) {
    if (a > b) return a;
    return b;
}

signed main() {
    cin >> test;
    while (test--) {
        int n1;
        n = 0; res = 0;
        cin >> n1 >> m;
        for (int i = 1; i <= n1; ++i) {
            cin >> a1[1] >> a1[2] >> a1[3];
            sort(a1 + 1, a1 + 4);
            a[++n] = {a1[1], a1[2], a1[3]};
            a[++n] = {a1[1], a1[3], a1[2]};
            a[++n] = {a1[2], a1[3], a1[1]};
        }
        for (int i = 1 + n; i <= m + n; ++i) cin >> b[i].r >> b[i].h;
        for (int i = 1; i <= n + m; ++i)
            for (int j = 1; j <= n + m; ++j) f[i][j] = 0;
        for (int i = 1; i <= n + m; ++i) {
            if (i <= n) f[1][i] = a[i].z;
            else f[1][i] = b[i].h;
            res = max1(res, f[1][i]);
        }
        for (int i = 1; i <= n + m - 1; ++i)
            for (int j = 1; j <= n + m; ++j) if (f[i][j]) {
                for (int k = 1; k <= n + m; ++k) {
                    if (k <= n && j > n && (sqrt(a[k].x * a[k].x + a[k].y * a[k].y) / 2) < b[j].r) f[i + 1][k] = max1(f[i + 1][k], f[i][j] + a[k].z);
                    if (k <= n && j <= n && a[j].x > a[k].x && a[j].y > a[k].y) f[i + 1][k] = max1(f[i + 1][k], f[i][j] + a[k].z);
                    if (k > n && j <= n && b[k].r < (a[j].x / 2)) f[i + 1][k] = max1(f[i + 1][k], f[i][j] + b[k].h);
                    if (k > n && j > n && b[j].r > b[k].r) f[i + 1][k] = max1(f[i + 1][k], f[i][j] + b[k].h);
                    res = max1(res, f[i + 1][k]);
                }
            }
        cout << res << endl;
    }
}
