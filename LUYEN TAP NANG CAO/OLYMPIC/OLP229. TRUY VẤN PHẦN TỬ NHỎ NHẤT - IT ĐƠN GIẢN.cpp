#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll val, idx;
};

const ll INF = (ll)9e18;

int n, m;
vector<ll> a;
vector<Node> t;

Node bestNode(const Node& a, const Node& b) {
    if (a.val < b.val) return a;
    if (b.val < a.val) return b;
    return (a.idx < b.idx) ? a : b; 
}

void build (ll v, ll l, ll r) { //v: stt của node, l và r là 2 đầu node đó quản lý
    if (l == r){
        t[v] = {a[l], l};
        return;
    } else {
        ll m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        t[v] = bestNode (t[v * 2], t[v * 2 + 1]);
    }
}

// Thay đổi 1 phần tử trong mảng thành giá trị nào đó
// pos: vị trí của phần tử cần thay đổi, val: giá trị mới, v: stt của node hiện tại, l và r là 2 đầu của node đó
void update (ll v, ll l, ll r, ll pos, ll val) {
    if (l == r){
        a[pos] = val;
        t[v] = {a[l], l};
        return;
    } else {
        ll m = (l + r) / 2;
        if (pos <= m) update(v * 2, l, m, pos, val);
        else update(v * 2 + 1, m + 1, r, pos, val);
        t[v] = bestNode (t[v * 2], t[v * 2 + 1]);
    }
}

Node query(ll v, ll l, ll r, ll L, ll R) {
    if (L > R) return Node{INF, INT_MAX};
    if (l == L && r == R) return t[v];
    ll m = (l + r) / 2;
    return bestNode (query(v * 2, l, m, L, min(R, m)), query(v * 2 + 1, m + 1, r, max(L, m + 1), R));
}

int main(){
    cin >> n >> m;
    a.resize(n + 1);
    t.assign(4 * n + 5, Node{INF, INT_MAX}); 
    for (ll i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        ll type, x, y;
        cin >> type >> x >> y;
        if (type == 1) update(1, 1, n, x, y);
        else cout << query(1, 1, n, x, y).idx << '\n';
    }
}
