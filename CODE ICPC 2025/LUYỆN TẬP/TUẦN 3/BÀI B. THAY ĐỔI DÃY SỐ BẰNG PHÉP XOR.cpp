#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18 + 7;
const ll mxn = 1e5 + 7;

ll n, a[mxn];
int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    a[0] = -INF;
    a[n + 1] = INF;
    ll res = INF;
    for (ll i = 1; i <= n; i++) {
        ll cur = 0;
        for (ll j = i; j >= 1; j--) {
            ll lenLeft = i - j + 1;
            if (lenLeft >= res) break;
            cur ^= a[j];
            ll mx = 0;
            for (ll k = i + 1; k <= n; k++) {
                ll lenRight = k - i;
                if (lenLeft + lenRight - 2 >= res) break;
                mx ^= a[k];
                if (mx < cur) {
                    res = min(res, lenLeft + lenRight - 2);
                    break;
                }
            }
        }
    }
    cout << (res == INF ? -1 : res);
}
