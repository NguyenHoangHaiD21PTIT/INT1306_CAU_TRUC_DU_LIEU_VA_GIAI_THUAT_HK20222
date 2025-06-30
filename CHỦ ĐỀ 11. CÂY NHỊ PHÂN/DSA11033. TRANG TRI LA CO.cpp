#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Sắp xếp theo điểm kết thúc tăng dần
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> st, en;
    for (ll i = 0; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        st.push_back({u, v});
        en.push_back({u, v});
    }
    sort(st.begin(), st.end());          // theo U tăng dần
    sort(en.begin(), en.end(), cmp);     // theo V tăng dần
    ll q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        // Tìm vị trí pos đầu tiên mà st[pos] > x --> [0; pos - 1] là tập các đoạn có điểm bắt đầu <=x
        ll l = -1, r = st.size();
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (st[mid].first > x) r = mid;//Ở mid đã > x --> Thu hẹp phạm vi tìm kiếm xem còn có pos < x k
            else l = mid;
        }
        ll cnt1 = r;
        // Tìm vị trí pos cuối cùng mà en[pos] < x --> [0; pos] là tập các đoạn có điểm kết thúc < x
        l = -1; r = en.size();
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (en[mid].second < x) l = mid;
            else r = mid;
        }
        ll cnt2 = l + 1;
        cout << (cnt1 - cnt2) << '\n';
    }
}
