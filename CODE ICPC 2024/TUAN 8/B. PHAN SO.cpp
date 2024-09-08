#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int, int>
const int N = 2e7+5, M = 1e3+5, MOD = 1e9+7, inf = 1e18;
int n, m, x, y, res, test, cnt1, sum, k, hs;
int a[N], h[N];
string s, s1;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s1;
    y = (int) s1.size(); k = 1; res = 0;
    for (char x: s1) hs = (hs * 31 + x - '0' + 1) % MOD;
    for (int i = 1; i <= y; ++i) k = (k * 31) % MOD;
    int ans = n / m, du = n % m;
    while (1) {
        a[++x] = ans % 10;
        ans /= 10;
        if (ans == 0) break;
    }
    reverse(a + 1, a + x + 1);
    for (int i = 1; i <= x; ++i) {
        //cout << du << endl;
        h[i] = (h[i - 1] * 31 + a[i] + 1) % MOD;
        if (i >= y && (h[i] - h[i - y] * k + MOD * MOD) % MOD == hs) {
            res = i - y + 1;
            break;
        }
    }
    while (!res && x < N) {
        a[++x] = du * 10 / m;
        //cout << a[x] << endl;
        du = du * 10 - a[x] * m;
        h[x] = (h[x - 1] * 31 + a[x] + 1) % MOD;
        if (x >= y && (h[x] - h[x - y] * k + MOD * MOD) % MOD == hs) {
            res = x - y + 1;
            break;
        }
    }
    cout << res;
}
