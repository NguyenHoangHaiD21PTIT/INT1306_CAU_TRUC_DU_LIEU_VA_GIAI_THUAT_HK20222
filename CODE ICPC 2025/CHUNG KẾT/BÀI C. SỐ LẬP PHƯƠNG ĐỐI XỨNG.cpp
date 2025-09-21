#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll x) {
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    ll N, ans = 0; cin >> N;
    for (ll x = 1; x <= cbrt(N); x++) {
        ll cube = x * x * x;
        if (cube > N) break;
        if (check(cube)) ans = max(ans, cube);
    }
    cout << ans;
}
