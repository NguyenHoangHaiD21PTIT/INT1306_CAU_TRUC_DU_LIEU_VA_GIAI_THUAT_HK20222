#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main() {
    int n;
    cin >> n;
    vector<ll> h(n), p(n);
    for (int i = 0; i < n; ++i) cin >> h[i] >> p[i];
    //Sắp xếp theo chiều cao tăng dần
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return tie(h[a], a) < tie(h[b], b);
    });
    vector<ll> hs(n), ps(n);
    for (int i = 0; i < n; ++i) {
        hs[i] = h[order[i]];
        ps[i] = p[order[i]];
    }
    //Tìm xa nhất (j) mà đi từ vị trí i mà chỉ cần trả đúng mức sàn ps[i], h[j] - h[i] <= p[i] --> h[j] <= p[i] + h[i]
    //f[i] = j: Từ i có thể đi xa nhất là đến j mà chỉ cần trả đúng mức sàn xuất phát
    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        ll T = hs[i] + ps[i];
        int j = upper_bound(hs.begin(), hs.end(), T) - hs.begin() - 1;
        f[i] = j;
    }
    //Prefix max m[i]
    vector<int> m(n);
    m[0] = f[0];
    for (int i = 1; i < n; ++i) m[i] = max(m[i - 1], f[i]);
    // Tách dãy 0..n-1 thành các đoạn con liên tiếp [start, i] sao cho trong mỗi đoạn đó, từ bất kỳ vị trí nào ta đều có thể "nhảy free" đến cuối đoạn
    vector<pair<int, int>> segs;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (m[i] == i) {
            segs.emplace_back(start, i);
            start = i + 1;
        }
    }

    ll extra = 0;
    for (int t = 0; t + 1 < (int)segs.size(); ++t) {
        int L = segs[t].first, R = segs[t].second;
        int nextL = segs[t + 1].first;
        ll maxT = 0;
        for (int i = L; i <= R; ++i) maxT = max(maxT, hs[i] + ps[i]);
        ll minHn = hs[nextL];
        if (minHn > maxT) extra += (minHn - maxT);
    }
    ll total_p = accumulate(ps.begin(), ps.end(), 0LL);
    cout << total_p + extra << '\n';
    return 0;
}
// Sưu tầm
