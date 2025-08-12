#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, int>> fac(long long k) {
    vector<pair<ll, int>> res;
    for (ll d = 2; d * d <= k; ++d) {
        if (k % d == 0) {
            int dem = 0;
            while (k % d == 0) {
                k /= d;
                ++dem;
            }
            res.push_back({d, dem});
        }
    }
    if (k > 1) res.push_back({k, 1});
    return res;
}

// Hàm tính số lần xuất hiện của số nguyên tố p trong N!
ll dem(ll n, ll p) {
    ll dem = 0;
    while (n >= p) {
        dem += n / p;
        n /= p;
    }
    return dem;
}

// Hàm tính số nguyên M lớn nhất sao cho K^M là ước của N!
ll maxPow(ll n, ll k) {
    vector<pair<ll, int>> f = fac(k);
    ll ans = LLONG_MAX;
    for (auto& ts: f) {
        ll p = ts.first;//thừa số
        int e = ts.second;//số mũ
        ll demP = dem(n, p);
        ans = min(ans, demP / e);
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t --) {
        ll N, K;
        cin >> N >> K;
        cout << maxPow(N, K) << '\n';
    }
    return 0;
}
/*Giả sử N! = a^x.b^y.c^z. 
K = a^x1.b^x2.c^x3 --> K^M = a ^ (M * x1) * b ^ (M * x2) * c ^ (M * x3)
Để N! chia hết cho K^M thì M * x1 <= x, M * x2 <= y, M * x3 <= z
-->M <= x / x1, M <= y / x2, M <= z / x3
M nguyên -->M <= min([x / x1], [y / x2], [z / x3])
Dấu bằng xảy ra M đạt GTLN = min([x1/x1],[y/x2], [z/x3])
*/
