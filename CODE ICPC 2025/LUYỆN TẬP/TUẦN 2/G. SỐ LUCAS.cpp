#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    ll f[95] = {};
    f[0] = 2; f[1] = 1;
    for(ll i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
    cout << f[n];
}
