#include <bits/stdc++.h>
using namespace std;
struct B {
    int h, t;
};
bool cmp(const B &A, const B &B) {
    return A.h > B.h;
}
int id(int x, int y, int W) {
    return x * (W + 1) + y;
}
int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<B> a(n);
        int tot = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].h >> a[i].t;
            tot += a[i].t;
        }
        sort(a.begin(), a.end(), cmp);
        const int INF = 1e9;
        int W = tot, SZ = (W + 1) * (W + 1);
        vector<int> dp(SZ, INF), ndp(SZ, INF);
        dp[id(0, 0, W)] = 0;
        int s = 0;
        vector<int> touched; touched.reserve(SZ);
        for (auto bk : a) {
            int h = bk.h, t = bk.t;
            for (int w1 = 0; w1 <= s; w1++) {
                for (int w2 = 0; w2 <= s - w1; w2++) {
                    int val = dp[id(w1, w2, W)];
                    if (val == INF) continue;
                    int w3 = s - w1 - w2;
                    {
                        int x = w1 + t, y = w2;
                        int add = (w1 == 0 ? h : 0);
                        int idx = id(x, y, W), nv = val + add;
                        if (ndp[idx] == INF) touched.push_back(idx);
                        ndp[idx] = min(ndp[idx], nv);
                    }
                    // cho vào tầng 2
                    {
                        int x = w1, y = w2 + t;
                        int add = (w2 == 0 ? h : 0);
                        int idx = id(x, y, W), nv = val + add;
                        if (ndp[idx] == INF) touched.push_back(idx);
                        ndp[idx] = min(ndp[idx], nv);
                    }
                    // cho vào tầng 3
                    {
                        int idx = id(w1, w2, W);
                        int add = (w3 == 0 ? h : 0);
                        int nv = val + add;
                        if (ndp[idx] == INF) touched.push_back(idx);
                        ndp[idx] = min(ndp[idx], nv);
                    }
                }
            }
            s += t;
            dp.swap(ndp);
            for (int idx : touched) ndp[idx] = INF;
            touched.clear();
        }
        long long ans = LLONG_MAX;
        for (int w1 = 1; w1 <= W - 2; w1++) {
            for (int w2 = 1; w2 <= W - w1 - 1; w2++) {
                int val = dp[id(w1, w2, W)];
                if (val == INF) continue;
                int w3 = W - w1 - w2;
                int wmax = max({w1, w2, w3});
                ans = min(ans, 1LL * val * wmax);
            }
        }
        cout << ans << '\n';
    }
}
