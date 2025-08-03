#include <bits/stdc++.h>
using namespace std;

const int mxn = 5e5 + 9;

struct Node {
    int ans, l, r;
};

int n, q, lz[mxn * 4];
Node st[mxn * 4];

void push(int id, int l, int r) {
    if (!lz[id]) return;
    int m = (l + r) >> 1;
    int val = lz[id];
    if (val == -1) {
        st[id * 2] = {m - l + 1, m - l + 1, m - l + 1};
        st[id * 2 + 1] = {r - m, r - m, r - m};
    } else st[id * 2] = st[id * 2 + 1] = {0, 0, 0};
    lz[id * 2] = lz[id * 2 + 1] = val;
    lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (r < u || v < l) return;
    if (u <= l && r <= v) {
        lz[id] = val ? 1 : -1;
        int len = r - l + 1;
        st[id] = val ? Node{0, 0, 0} : Node{len, len, len};
        return;
    }
    push(id, l, r);
    int m = (l + r) >> 1;
    update(id * 2, l, m, u, v, val);
    update(id * 2 + 1, m + 1, r, u, v, val);
    Node &L = st[id * 2], &R = st[id * 2 + 1];
    st[id] = {
        max({L.ans, R.ans, L.r + R.l}),
        (L.l == m - l + 1) ? L.l + R.l : L.l,
        (R.r == r - m) ? R.r + L.r : R.r
    };
}

Node query(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return {-1, -1, -1};
    if (u <= l && r <= v) return st[id];
    push(id, l, r);
    int m = (l + r) >> 1;
    Node L = query(id * 2, l, m, u, v);
    Node R = query(id * 2 + 1, m + 1, r, u, v);
    if (L.ans == -1) return R;
    if (R.ans == -1) return L;
    return {
        max({L.ans, R.ans, L.r + R.l}),
        (L.l == m - l + 1) ? L.l + R.l : L.l,
        (R.r == r - m) ? R.r + L.r : R.r
    };
}

int main() {
    cin >> n >> q;
    update(1, 1, n, 1, n, 0); 
    int res = 0;
    while (q--) {
        char type;
        cin >> type;
        if (type == 'A') {
            int k;
            cin >> k;
            int l = 0, r = n + 1;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (query(1, 1, n, 1, m).ans >= k) r = m;
                else l = m;
            }
            if (r <= n) update(1, 1, n, r - k + 1, r, 1);
            else ++res;
        } else {
            int l, r;
            cin >> l >> r;
            update(1, 1, n, l, r, 0);
        }
    }
    cout << res;
}
//Sưu tầm
