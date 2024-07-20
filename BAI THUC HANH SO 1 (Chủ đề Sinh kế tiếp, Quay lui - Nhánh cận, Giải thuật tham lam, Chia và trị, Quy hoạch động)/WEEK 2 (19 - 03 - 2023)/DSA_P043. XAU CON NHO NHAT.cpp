#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size(), k = 0, st = 0, ans = INT_MAX, x = 0, a[256] = {};//st: start: điểm bắt đầu xâu con
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        map<char, int> m;
        //k: số ký tự phân biệt trong xâu
        for (char c : s) {
            if (!m[c]++) k++;
        }
        for (int i = 0; i < n; i++) {
            a[s[i]]++;
            if (a[s[i]] == 1) x++;
            if (x == k) {
                while (a[s[st]] > 1) {
                    a[s[st]] = a[s[st]] - 1;
                    st++;
                }
                ans = min(ans, i - st + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
