#include <bits/stdc++.h>
using namespace std;
#define int long long
int test, x, y, res, s, t;

void sub12() {
    res = 0;
    x = x % y;
    int i = 0;
    while (i < t) {
        ++i;
        if (i >= s) res = (res + x * 10 / y) % y;
        x = x * 10 % y;
    }
    cout << res << endl;
}

signed main() {
    cin >> test;
    while (test--) {
        cin >> x >> y >> s >> t;
        sub12();
    }
}
