#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int T, n;
ii seg[105];
int grundy[105][105];

int dp(int l, int r) {
    if (l > r) return 0;
    if (grundy[l][r] != -1) return grundy[l][r];
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int L = seg[i].first, R = seg[i].second;
        if (L >= l && R <= r) {
            int left = dp(l, L - 1);
            int right = dp(R + 1, r);
            s.insert(left ^ right);
        }
    }
    int mex = 0;
    while (s.count(mex)) ++mex;
    return grundy[l][r] = mex;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> seg[i].first >> seg[i].second;
        memset(grundy, -1, sizeof grundy);
        int res = dp(1, 100);
        cout << (res ? "Alice" : "Bob") << '\n';
    }
} 
