#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> pr;
void sv() {
    const int N = 1e7;
    vector<bool> isp(N + 1, true);
    isp[0] = isp[1] = false;
    for (ll i = 2; i * i <= N; i++) {
        if (isp[i]) {
            for (ll j = i * i; j <= N; j += i) isp[j] = false;
        }
    }
    for (ll i = 2; i <= N; i++){
        if (isp[i]) pr.push_back(i);
    }
}
int main() {
    sv(); int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        for (ll p : pr) {
            if (p * p > n) break;
            if (n % p == 0) {
                int c = 0;
                while (n % p == 0) {
                    c++;
                    n /= p;
                }
                cout << p << " " << c << "\n";
            }
        }
        if (n > 1) cout << n << " 1\n";
        cout << "\n";
    }
}
