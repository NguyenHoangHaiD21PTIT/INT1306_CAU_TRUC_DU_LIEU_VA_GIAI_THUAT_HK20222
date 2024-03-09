#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    set<char> tmp;
    int ans = 0;
    for (char x : s) {
        tmp.insert(x);
        ans = max(ans, int(x));
    }
    int d[ans + 5][s.size() + 5] = {};
    for (int i = 1; i <= s.length(); ++i) {
        for (char x : tmp) {
            if (x == s[i - 1]) d[int(x)][i] = d[int(x)][i - 1] + 1;
            else d[int(x)][i] = d[int(x)][i - 1];
        }
    }
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_) {
        int a, b, c, d1;
        cin >> a >> b >> c >> d1;
        int ok = 1;
        for (char x : tmp) {
            if (d[int(x)][b] - d[int(x)][a - 1] != d[int(x)][d1] - d[int(x)][c - 1]) {
                ok = 0;
                break;
            }
        }
        if (ok == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
//Submit bài này tai đây nhé: https://www.spoj.com/PTIT/problems/P18QPROF/
