#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ii pair<int, int>
const int N = 2e7+300, M = 1e2+5, MOD = 1e9+7;
int n, m, x, y, res, test, cnt, sum, k;
int a[N], nt[N], kt[N], c[N];
long long t[N];

void sol(int n) {
    while (n > 1) {
        ++t[nt[n]];
        n /= nt[n];
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], k = max(k, a[i]);
    k += 200;
    for (int i = 2; i * i <= k; ++i) if (!nt[i]) {
        for (int j = i; j <= k; j += i)
            if (!nt[j]) nt[j] = i, kt[j] = (j > i ? 1 : 0);
    }
    for (int i = 2; i <= k; ++i) {
        if (!nt[i]) nt[i] = i;
        if (!kt[i]) c[++cnt] = i;
    }
    for (int i = 1; i <= n; ++i) {
        if ((a[i] == 1) || (i > 1 && a[i] == 0 && a[i - 1] == 0) || (i > 1 && a[i] && a[i - 1] && __gcd(a[i], a[i - 1]) != 1)) {
            x = 1;
            break;
        }
        if (a[i] > 1 && ((i > 1 && a[i - 1] == 0) || (i < n && a[i + 1] == 0))) sol(a[i]), ++y;
    }
    if (x) cout << -1;
    else if (y == 0) cout << 1;
    else {
        for (int i = 1; i <= cnt; ++i)
        if (t[c[i]] == 0) {
            cout << c[i];
            break;
        }
    }
}
