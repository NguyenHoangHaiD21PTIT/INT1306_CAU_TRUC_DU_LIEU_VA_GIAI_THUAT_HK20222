#include <bits/stdc++.h>
using namespace std;

map<string, int> M;

int f(string &s) {
    if (s.empty()) return 0;
    if (M.count(s)) return M[s];
    int n = s.size(), res = INT_MAX;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j + 1 < n && s[j + 1] == s[i]) j++;
        // xóa đoạn s[i..j]
        string t = s.substr(0, i) + s.substr(j + 1);
        res = min(res, 1 + f(t));
        i = j + 1;
    }
    return M[s] = res;
}

int main() {
    int n; string s;
    cin >> n >> s;
    cout << f(s) << "\n";
}
