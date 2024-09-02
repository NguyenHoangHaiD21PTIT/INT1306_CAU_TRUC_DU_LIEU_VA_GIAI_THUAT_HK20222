#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int stX, stY, enX, enY, n;
string S;

bool canReachIn(ll k) {
    ll x = stX, y = stY;
    ll dx = 0, dy = 0;
    for (int i = 0; i < (k % n); ++i) {
        if (S[i] == 'U') y++;
        if (S[i] == 'D') y--;
        if (S[i] == 'R') x++;
        if (S[i] == 'L') x--;
    }
    for (int i = 0; i < min(1LL * n, k); ++i) {
        if (S[i] == 'U') dy++;
        if (S[i] == 'D') dy--;
        if (S[i] == 'R') dx++;
        if (S[i] == 'L') dx--;
    }
    x += dx * (k / n);
    y += dy * (k / n);
    ll distance = abs(enX - x) + abs(enY - y);
    return (distance <= k);
}

int main() {
    cin >> stX >> stY >> enX >> enY >> n >> S;
    ll l = 0, r = 1e18;
    ll ans = -1;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (canReachIn(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans;
}
