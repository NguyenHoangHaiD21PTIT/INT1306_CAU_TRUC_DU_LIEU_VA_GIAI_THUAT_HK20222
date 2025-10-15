#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100005, MOD = 1e9 + 9;

ll a[MAXN], st[4 * MAXN];
pair<ll, ll> lz[4 * MAXN];
ll f[MAXN];
int n, m;

void addp(pair<ll, ll>& p1, const pair<ll, ll>& p2) {
    p1.first = (p1.first + p2.first) % MOD;
    p1.second = (p1.second + p2.second) % MOD;
}

void pre() {
    f[1] = 1; f[2] = 1;
    for (int i = 3; i < MAXN; ++i) f[i] = (f[i - 1] + f[i - 2]) % MOD;
}

ll get(ll a, ll b, int len) {
    if (len <= 0) return 0;
    if (len == 1) return a;
    ll val = (a * f[len] + b * f[len + 1]) % MOD;
    return (val - b + MOD) % MOD;
}

void push(int id, int l, int r) {
    if (lz[id].first == 0 && lz[id].second == 0) return;
    ll fa = lz[id].first, fb = lz[id].second;
    st[id] = (st[id] + get(fa, fb, r - l + 1)) % MOD;
    if (l != r) {
        int mid = (l + r) / 2;
        int len_l = mid - l + 1;
        addp(lz[id * 2], {fa, fb});
        ll na = (fa * f[len_l - 1] + fb * f[len_l]) % MOD;
        ll nb = (fa * f[len_l] + fb * f[len_l + 1]) % MOD;
        addp(lz[id * 2 + 1], {na, nb});
    }
    lz[id] = {0, 0};
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = (st[id * 2] + st[id * 2 + 1]) % MOD;
}

void upd(int id, int l, int r, int u, int v) {
    push(id, l, r);
    if (v < l || u > r) return;
    if (u <= l && r <= v) {
        addp(lz[id], {f[l - u + 1], f[l - u + 2]});
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, u, v);
    upd(id * 2 + 1, mid + 1, r, u, v);
    st[id] = (st[id * 2] + st[id * 2 + 1]) % MOD;
}

ll get(int id, int l, int r, int u, int v) {
    push(id, l, r);
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return (get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v)) % MOD;
}

int main() {
    pre(); f[0] = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) upd(1, 1, n, l, r);
        else cout << get(1, 1, n, l, r) << "\n";
    }
}
