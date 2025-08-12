#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll mx1, mx2; // 2 giá trị lớn nhất
    Node(ll a = LLONG_MIN, ll b = LLONG_MIN) : mx1(a), mx2(b) {}
};

const ll INF = (ll)9e18;

ll n, m;
vector<ll> a;
vector<Node> t;

Node mergeNode(const Node& L, const Node& R) {
    ll c[4] = {L.mx1, L.mx2, R.mx1, R.mx2};
    sort(c, c + 4, greater<ll>());
    return Node(c[0], c[1]); 
}

void build (ll v, ll l, ll r) {
    if (l == r){
        t[v] = {a[l], LLONG_MIN};
    } else {
        ll mid = (l + r) / 2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        t[v] = mergeNode(t[v * 2], t[v * 2 + 1]);
    }
}

void update (ll v, ll l, ll r, ll pos, ll val) {
    if (l == r){
        a[pos] = val;
        t[v] = {val, LLONG_MIN};
    } else {
        ll mid = (l + r) / 2;
        if (pos <= mid) update(v * 2, l, mid, pos, val);
        else update(v * 2 + 1, mid + 1, r, pos, val);
        t[v] = mergeNode(t[v * 2], t[v * 2 + 1]);
    }
}

Node query(ll v, ll l, ll r, ll L, ll R) {
    if (L > R) return Node(LLONG_MIN, LLONG_MIN);
    if (l == L && r == R) return t[v];
    ll mid = (l + r) / 2;
    return mergeNode(query(v * 2, l, mid, L, min(R, mid)), query(v * 2 + 1, mid + 1, r, max(L, mid + 1), R));
}

int main(){
    cin >> n >> m;
    a.resize(n + 1);
    t.assign(4 * n + 5, Node());
    for (ll i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        char type; ll x, y;
        cin >> type >> x >> y;
        if (type == 'U') {
            update(1, 1, n, x, y);
        } else { 
            Node res = query(1, 1, n, x, y);
            cout << res.mx1 + res.mx2 << "\n";
        }
    }
}
