#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MAXN = 1e7 + 7;

ll n, m, a[100001], f[MAXN], pf[MAXN];

void prep() {
    f[0] = 1;
    for (ll i = 1; i <= 1e7; i++) f[i] = f[i - 1] * i % m; //Tính X!
    for (ll i = 1; i <= 1e7; i++) pf[i] = (pf[i - 1] + f[i] * i % m) % m; 
    //pr[X] = 1! * 1 + 2! * 2 + ... + X! * X
}

//1*(1! + x) + 2*(2! + x) + … + x*(x! + x) = (1*(1!) + 2*(2!) + … + x*(x!)) + (1 + 2 + … + x) * x
//Mà (1 + 2 + … + x) * x = x * (x + 1) * x / 2

ll poly(ll x) {
    ll p1, p2, p3 = x % m;
    if (x % 2 == 1) {
        p1 = (x + 1) / 2 % m;
        p2 = x % m;
    } else {
        p1 = x / 2 % m;
        p2 = (x + 1) % m;
    }
    ll res = p1 * p2 % m * p3 % m;
    return res;
}

int main() {
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    prep();
    ll ans = 0;
    //X > M --> 1*(1!) + 2*(2!) + … + M*(M!) + ...
    //Toàn bộ những M!, (M + 1)! cho đến hết đều chứa M cho nên mọi cái p! * p với p > M thì đều chia hết cho M
    //Nên khi X > M thì chỉ cần tính 1*(1!) + 2*(2!) + ... cho đến M - 1 thôi, vì sau M thì chia hết cho M rồi
    for (ll i = 1; i <= n; i++) {
        if (a[i] >= m) ans += pf[m - 1];
        else ans += pf[a[i]];
        ans += poly(a[i]);
        ans %= m;
    }
    cout << ans;
}
