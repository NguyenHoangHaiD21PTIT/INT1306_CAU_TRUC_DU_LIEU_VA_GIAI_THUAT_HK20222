#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 1e6 + 5;

ll n;
pair<ll, ll> p[MAXN], sx[MAXN], sy[MAXN];

bool cmpY(pair<ll,ll> a, pair<ll,ll> b) {
    return a.second < b.second;
}

ll calc(ll mid) {
    ll mx = sx[mid].first, my = sy[mid].second; //Sắp xếp toạ độ x, y tăng dần để lấy trung vị
    ll ex = 0, ey = 0;
    ll cx = mx, cy = my;// Giữ hàng dọc: Fix cứng x = mx, giữ hàng ngang: y = my
    // Tinh theo Y (Cố định x): Xếp dọc
    // Xếp tất cả trên đường thẳng song song với trục tung là x = x_mid, xếp thằng giữa nhất vào y = y_mid, thằng lớn hơn thì đi lên 1 đơn vị trên trục tung, cứ thế, ...
    for (ll i = mid; i <= n; i++) {
        ey += abs(sy[i].first - mx) + abs(sy[i].second - cy);
        cy++;
    }
    cy = my - 1;
    for (ll i = mid - 1; i >= 1; i--) {
        ey += abs(sy[i].first - mx) + abs(sy[i].second - cy);
        cy--;
    }
    // Tinh theo X
    for (ll i = mid; i <= n; i++) {
        ex += abs(cx - sx[i].first) + abs(my - sx[i].second);
        cx++;
    }
    cx = mx - 1;
    for (ll i = mid - 1; i >= 1; i--) {
        ex += abs(cx - sx[i].first) + abs(my - sx[i].second);
        cx--;
    }
    return min(ex, ey);
}

int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
        sx[i] = sy[i] = p[i];
    }
    sort(sx + 1, sx + n + 1);
    sort(sy + 1, sy + n + 1, cmpY);
    cout << calc((n + 1) / 2);
}
