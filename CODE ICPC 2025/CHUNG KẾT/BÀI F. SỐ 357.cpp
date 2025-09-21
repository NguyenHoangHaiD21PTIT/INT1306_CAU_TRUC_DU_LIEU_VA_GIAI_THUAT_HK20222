#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is357(ll x) {
    bool c3 = false, c5 = false, c7 = false;
    while (x > 0) {
        int d = x % 10;
        if (d == 3) c3 = true;
        else if (d == 5) c5 = true;
        else if (d == 7) c7 = true;
        x /= 10;
    }
    return c3 && c5 && c7;
}

int main() {
    ll N; cin >> N;
    queue<ll> q;
    q.push(3); q.push(5); q.push(7);
    ll ans = 0;
    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        if (is357(x)) ans++;
        for (int d: {3, 5, 7}) {
            ll y = x * 10 + d;
            if (y <= N) q.push(y);
        }
    }
    cout << ans;
}
