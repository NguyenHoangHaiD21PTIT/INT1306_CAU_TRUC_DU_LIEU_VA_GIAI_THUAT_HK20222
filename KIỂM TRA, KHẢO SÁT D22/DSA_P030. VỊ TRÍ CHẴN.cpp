#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const LL MOD = 1e9 + 7;
const int MAX = 2005;

int M, D;
LL dp[MAX][2][MAX];
string L, R;
vector<int> A;

LL cal(int p, bool t, int r) {
    if (p == A.size()) return r == 0;
    LL &res = dp[p][t][r];
    if (res != -1) return res;
    res = 0;
    int lim = t ? A[p] : 9;
    for (int c = 0; c <= lim; ++c) {
        bool ok = true;
        if (p % 2 == 0) {
            if (c == D) ok = false;
        } else {
            if (c != D) ok = false;
        }
        if (!ok) continue;
        bool nt = t && (c == A[p]);
        int nr = (r * 10 + c) % M;
        res = (res + cal(p + 1, nt, nr)) % MOD;
    }
    return res;
}

LL sol(const string &s) {
    A.clear();
    for (char c : s) A.push_back(c - '0');
    memset(dp, -1, sizeof(dp));
    return cal(0, true, 0);
}

int main() {
    cin >> M >> D >> L >> R;
    LL ans = (sol(R) - sol(L) + MOD) % MOD;
    bool L_ok = true;
    int cur_r = 0;
    for (int i = 0; i < L.length(); ++i) {
        int d = L[i] - '0';
        if (i % 2 == 0) {
            if (d == D) {
                L_ok = false;
                break;
            }
        } else {
            if (d != D) {
                L_ok = false;
                break;
            }
        }
        cur_r = (cur_r * 10 + d) % M;
    }

    if (L_ok && cur_r != 0) L_ok = false;
    if (L_ok) ans = (ans + 1) % MOD;
    cout << ans << "\n";
}
