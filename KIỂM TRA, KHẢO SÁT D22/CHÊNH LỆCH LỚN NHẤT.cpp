#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; string s;
    cin >> n >> s;
    int res = 0;
    for (char x = 'a'; x <= 'z'; x++) {
        for (char y = 'a'; y <= 'z'; y++) {
            if (x == y) continue;
            int cur = 0, mx = INT_MIN;
            bool seen = false;
            for (char ch : s) {
                if (ch == x) cur++;
                if (ch == y) {
                    cur--;
                    seen = true;
                }
                if (seen) mx = max(mx, cur);
                if (cur < 0) {
                    cur = 0;
                    seen = false;
                }
            }
            if (mx != INT_MIN) res = max(res, mx);
        }
    }
    cout << res << "\n";
    return 0;
}
