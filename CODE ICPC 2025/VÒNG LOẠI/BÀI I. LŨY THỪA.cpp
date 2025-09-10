#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
// Trả về true nếu a^e <= lim
bool leq(ll a, int e, ll lim) {
    ll res = 1;
    for (int i = 0; i < e; i++) {
        if (res > lim / a) return false;
        res *= a;
    }
    return res <= lim;
}
 
// Trả về true nếu a^e == t
bool eq(ll a, int e, ll t) {
    ll res = 1;
    for (int i = 0; i < e; i++) {
        if (res > t / a) return false;
        res *= a;
    }
    return res == t;
}
 
//Tìm y lớn nhất sao cho y^k <= x, với x và k cho trước
ll kth(ll x, int k) {
    if (k == 1) return x;
    ll lo = 1, hi = x, ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (leq(mid, k, x)) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    return ans;
}
 
// Đếm số ước của n
ll divs(ll n) {
    ll ans = 1;
    for (ll i = 2; i * i <= n && i <= 10000000LL; i++) {
        if (n % i == 0) {
            ll e = 0;
            while (n % i == 0) n /= i, e++;
            ans *= (e + 1);
        }
    }
    if (n > 1) ans *= 2;
    return ans;
}
 
int main() {
    ll x; cin >> x;
    for (int k = 61; k >= 1; k--) {
        if (k == 1) {
            if (x == 1) {
                cout << 1 << "\n";
                return 0;
            }
            continue;
        }
        ll n = kth(x, k);
        if (n && eq(n, k, x) && divs(n) == k) {
            cout << n << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}
