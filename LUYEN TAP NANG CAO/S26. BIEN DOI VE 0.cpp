#include <bits/stdc++.h>
using namespace std;

int cnt(int n) {
    int ans = 0;
    while (n > 0) {
        int x = n;
        while (x >= 10) x /= 10;
        n -= x;
        ans++;
    }
    return ans;
}

void solve() {
    int k;
    cin >> k;
    int l = 1, r = 1e6, res = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int steps = cnt(mid);
        if (steps <= k) {
            if (steps == k) res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
