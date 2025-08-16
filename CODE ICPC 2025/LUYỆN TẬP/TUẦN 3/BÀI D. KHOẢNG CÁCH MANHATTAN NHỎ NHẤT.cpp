#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Nhiệm vụ: Với N số trong mảng A, bỏ A[i] đi thì max và min của những số còn lại là gì?
auto rmov(const vector<ll> &a) {
    int n = a.size();
    vector<ll> preMax(n), preMin(n), sufMax(n), sufMin(n);
    //preMax[i] = max(a[0], a[1], ..., a[i]), preMin[i] = min(a[0], a[1], ..., a[i]), sufMax[i] = max(a[i], a[i+1], ..., a[n-1]), sufMin[i] = min(a[i], a[i+1], ..., a[n-1])
    preMax[0] = preMin[0] = a[0];
    for (int i = 1; i < n; i++) {
        preMax[i] = max(preMax[i-1], a[i]);
        preMin[i] = min(preMin[i-1], a[i]);
    }
    sufMax[n - 1] = sufMin[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        sufMax[i] = max(sufMax[i+1], a[i]);
        sufMin[i] = min(sufMin[i+1], a[i]);
    }
    vector<pair<ll,ll>> res(n); ///res[i] = {max, min} khi bỏ a[i]
    //Bỏ a[i] --> max = {max (a[0], a[1], ..., a[i - 1]), max (a[i + 1], a[i + 2], ..., a[n - 1])} = max(preMax[i - 1], sufMax[i + 1]), min = {min (a[0], a[1], ..., a[i - 1]), min (a[i + 1], a[i + 2], ..., a[n - 1])} = min(preMin[i - 1], sufMin[i + 1])
    for (int i = 0; i < n; i++) {
        ll mx = LLONG_MIN, mn = LLONG_MAX;
        if (i > 0) { 
            mx = max(mx, preMax[i - 1]); 
            mn = min(mn, preMin[i - 1]); 
        }
        if (i + 1 < n) { 
            mx = max(mx, sufMax[i + 1]); 
            mn = min(mn, sufMin[i + 1]); 
        }
        res[i] = {mx, mn};
    }
    return res;
}

int main() {
    int N; cin >> N;
    vector<ll> u(N), v(N);
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        u[i] = x + y;
        v[i] = x - y;
    }
    auto ru = rmov(u);
    auto rv = rmov(v);
    ll ans = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        ll du = ru[i].first - ru[i].second;
        ll dv = rv[i].first - rv[i].second;
        ans = min(ans, max(du, dv));
    }
    cout << ans << "\n";
}
/*
Ý tưởng: Khoảng cách Manhattan --> Khoảng cách Chebyshev
dM (A, B) = |xA - xB| + |yA - yB|
- Đặt u = x + y, v = x - y, xA - xB = dx, yA - yB = dy 
--> uA - uB = (xA + yA) - (xB + yB) = (xA - xB) + (yA - yB) = dx + dy
--> vA - vB = (xA - yA) - (xB - yB) = (xA - xB) - (yA - yB) = dx - dy
--> dM (A, B) = |dx| + |dy| = max(|dx + dy|, |dx - dy|) = max(|uA - uB|, |vA - vB|)
- Ta cần dM đạt max, thì 2 số trong hàm max phải đạt max --> Cần xác định được uMax, uMin, vMax, vMin 
- ru = {C[i], D[i]}, với C[i] và D[i] là max và min của các số trong ru khi bỏ u[i] đi
- rv = {E[i], F[i]}, với E[i] và F[i] là max và min của các số trong rv khi bỏ v[i] đi
*/
