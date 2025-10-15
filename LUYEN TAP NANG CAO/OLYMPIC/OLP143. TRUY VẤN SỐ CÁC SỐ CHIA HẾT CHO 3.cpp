#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, m, st[4 * MAXN][3], lz[4 * MAXN];
// st[id][0]: Lưu số lượng phần tử trong đoạn của nút id có số dư là 0.
void rot(int id, int k) {
    k %= 3;
    if (k == 0) return;
    if (k == 1) { // Xoay 1 vị trí
        int temp = st[id][2];
        st[id][2] = st[id][1];
        st[id][1] = st[id][0];
        st[id][0] = temp;
    } else { // Xoay 2 vị trí
        int temp = st[id][1];
        st[id][1] = st[id][2];
        st[id][2] = st[id][0];
        st[id][0] = temp;
    }
}

void push(int id) {
    if (lz[id] == 0) return;
    lz[id * 2] = (lz[id * 2] + lz[id]) % 3;
    lz[id * 2 + 1] = (lz[id * 2 + 1] + lz[id]) % 3;
    rot(id * 2, lz[id]);
    rot(id * 2 + 1, lz[id]);
    lz[id] = 0;
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id][0] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id][0] = st[id * 2][0] + st[id * 2 + 1][0];
}

void upd(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return;
    if (u <= l && r <= v) {
        lz[id] = (lz[id] + 1) % 3;
        rot(id, 1);
        return;
    }
    push(id);
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, u, v);
    upd(id * 2 + 1, mid + 1, r, u, v);
    st[id][0] = st[id * 2][0] + st[id * 2 + 1][0];
    st[id][1] = st[id * 2][1] + st[id * 2 + 1][1];
    st[id][2] = st[id * 2][2] + st[id * 2 + 1][2];
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return st[id][0];
    push(id);
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
    cin >> n >> m;
    build(1, 1, n);
    while (m--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 0) upd(1, 1, n, u, v);
        else cout << get(1, 1, n, u, v) << "\n";
    }
}
