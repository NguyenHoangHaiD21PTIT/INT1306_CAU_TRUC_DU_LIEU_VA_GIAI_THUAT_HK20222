#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int op, cl; // số ngoặc mở/đóng chưa khớp
    Node(int a = 0, int b = 0) : op(a), cl(b) {}
};

int n, q;
string s;
vector<Node> seg;

Node merge(const Node& L, const Node& R) {
    int m = min(L.op, R.cl); //L dấu mở bên trái, R dấu đóng bên phải, lấy min sẽ ra số cặp đã ghép
    return Node(L.op + R.op - m, L.cl + R.cl - m);
}

void build(int id, int l, int r) {
    if (l == r) {
        if (s[l] == '(') seg[id] = Node(1, 0);
        else seg[id] = Node(0, 1);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

void upd(int id, int l, int r, int pos, char c) {
    if (l == r) {
        seg[id] = (c == '(' ? Node(1, 0) : Node(0, 1));
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) upd(id * 2, l, mid, pos, c);
    else upd(id * 2 + 1, mid + 1, r, pos, c);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}

Node get(int id, int l, int r, int u, int v) {
    if (u > v) return Node(0, 0);
    if (l == u && r == v) return seg[id];
    int mid = (l + r) / 2;
    return merge(
        get(id * 2, l, mid, u, min(v, mid)),
        get(id * 2 + 1, mid + 1, r, max(u, mid + 1), v)
    );
}

int main() {
    cin >> n >> q >> s;
    s = " " + s; 
    seg.assign(4 * n + 5, Node());
    build(1, 1, n);
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            if (s[l] != s[r]) {
                swap(s[l], s[r]);
                upd(1, 1, n, l, s[l]);
                upd(1, 1, n, r, s[r]);
            }
        } else {
            Node res = get(1, 1, n, l, r);
            cout << ((res.op == 0 && res.cl == 0) ? "Yes\n" : "No\n");
        }
    }
}
