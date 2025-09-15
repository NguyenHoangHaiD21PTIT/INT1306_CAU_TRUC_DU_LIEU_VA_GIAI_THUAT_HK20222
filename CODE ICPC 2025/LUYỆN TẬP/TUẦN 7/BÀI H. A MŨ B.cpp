#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fsqrt(ll n) { //Không có hàm này thì 75/76(WA)
    long double r = sqrt((long double)n);
    ll s = (ll)r;
    while ((s + 1) * (s + 1) <= n) ++s;
    while (s * s > n) --s;
    return s;
}

bool issq(ll x) {
    ll s = fsqrt(x);
    return s * s == x;
}

int main() {
    ll N; cin >> N;
    //Ví dụ căn(50) = 7 phẩy mấy mấy thì auto có sẵn 1^2, 2^2, ..., 7^2
    ll ans = fsqrt(N);
    set<ll> S;
    //Sinh ra a^b
    for (int b = 3; b <= 60; ++b) {
        for (ll a = 2;; ++a) {
            ll v = 1;
            bool check = false;
            for (int k = 0; k < b; ++k) {
                if (v > N / a) { 
                    check = true; 
                    break; 
                }
                v *= a;
            }
            //check = true tức là chưa đến a^b đã tràn rồi thì (a + 1) ^ b cũng tràn thôi
            if (check) break;
            S.insert(v);
        }
    }
    for (auto v : S) if (!issq(v)) ++ans;
    cout << ans;
}
