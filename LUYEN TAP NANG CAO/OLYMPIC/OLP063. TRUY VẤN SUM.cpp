#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100005;
ll st[4 * MAXN], lz[4 * MAXN], a[MAXN];
int n, m;

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

void push(int id, int l, int r) {
    if (lz[id] == 0) return;
    st[id] += lz[id] * (r - l + 1);
    if (l != r) {
        lz[id * 2] += lz[id];
        lz[id * 2 + 1] += lz[id];
    }
    lz[id] = 0;
}

void upd(int id, int l, int r, int u, int v, int x) {
    push(id, l, r);
    if (v < l || u > r) return;
    if (u <= l && r <= v) {
        lz[id] += x;
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, u, v, x);
    upd(id * 2 + 1, mid + 1, r, u, v, x);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

ll get(int id, int l, int r, int u, int v) {
    push(id, l, r);
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int type, u, v, x;
        cin >> type >> u >> v;
        if (type == 1) {
            cout << get(1, 1, n, u, v) << "\n";
        } else {
            cin >> x;
            upd(1, 1, n, u, v, x);
        }
    }
}
