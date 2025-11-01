#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.length();
    string res = s;
    for (int i = 0; i < n; i++) {
        char d = s[i];
        string tmp = s;
        tmp.erase(i, 1); // Xóa 1 ký tự tại vị trí i
        string sf = d + tmp; res = max(res, sf);
        string sb = tmp + d; res = max(res, sb);
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) solve();
}
