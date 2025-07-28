#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int mod = 1e9 + 7;
struct Trie {
    vector<vector<int>> next;
    vector<int> end;
    int cnt;
    Trie(int n) : next(n + 5, vector<int>(26)), end(n + 5), cnt(0) {}
    void insert(string &s) {
        int u = 0;
        for (char ch : s) {
            int v = ch - 'a';
            if (!next[u][v]) next[u][v] = ++cnt;
            u = next[u][v];
        }
        end[u]++;
    }
};

int32_t main() {
    string s; cin >> s;
    int n = s.size(); s = ' ' + s;
    int k; cin >> k;
    Trie t(1e6);
    while (k--) {
        string word; cin >> word;
        reverse(word.begin(), word.end());
        t.insert(word);
    }
    vector<int> dp(n + 1); dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int u = 0;
        for (int j = i; j >= 1; j--) {
            int v = s[j] - 'a';
            if (!t.next[u][v]) break;
            u = t.next[u][v];
            if (t.end[u]) {
                dp[i] += dp[j - 1];
                if (dp[i] >= mod) dp[i] -= mod;
            }
        }
    }
    cout << dp[n] << '\n';
}
//Sưu tầm
