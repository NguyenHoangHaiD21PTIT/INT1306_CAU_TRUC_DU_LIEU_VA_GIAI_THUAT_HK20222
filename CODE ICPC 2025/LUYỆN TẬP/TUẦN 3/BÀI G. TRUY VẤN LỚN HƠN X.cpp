#include <bits/stdc++.h>
using namespace std;

struct SqrtBlocks {
    int n, B, numB;
    vector<long long> a;
    vector<vector<long long>> blk;
    void init(const vector<long long>& arr, int B_given = 700) {
        n = (int)arr.size() - 1;
        B = max(1, min(n, B_given));
        numB = (n + B - 1) / B;
        a = arr;
        blk.assign(numB, {});
        for (int i = 1; i <= n; ++i) blk[(i-1)/B].push_back(a[i]);
        for (auto &v : blk) sort(v.begin(), v.end());
    }
    void update(int pos, long long val) {
        int id = (pos-1) / B;
        auto &v = blk[id];
        v.erase(lower_bound(v.begin(), v.end(), a[pos]));
        v.insert(upper_bound(v.begin(), v.end(), val), val);
        a[pos] = val;
    }
    long long query(int l, int r, long long X) {
        if (l > r) return -1;
        long long ans = LLONG_MAX;
        int bl = (l-1)/B, br = (r-1)/B;
        if (bl == br) {
            for (int i = l; i <= r; ++i) if (a[i] > X) ans = min(ans, a[i]);
        } else {
            for (int i = l; i <= (bl+1)*B; ++i) if (a[i] > X) ans = min(ans, a[i]);
            for (int id = bl+1; id < br; ++id) {
                auto it = upper_bound(blk[id].begin(), blk[id].end(), X);
                if (it != blk[id].end()) ans = min(ans, *it);
            }
            for (int i = br*B+1; i <= r; ++i) if (a[i] > X) ans = min(ans, a[i]);
        }
        return (ans == LLONG_MAX ? -1 : ans);
    }
};

int main() {
    int N, M; 
    cin >> N >> M;
    vector<long long> a(N+1);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    SqrtBlocks ds; ds.init(a);
    while (M--) {
        int type; cin >> type;
        if (type == 1) {
            int u; long long val; cin >> u >> val;
            ds.update(u, val);
        } else {
            int u, v; long long X; cin >> u >> v >> X;
            cout << ds.query(u, v, X) << '\n';
        }
    }
}
//Tham khảo
