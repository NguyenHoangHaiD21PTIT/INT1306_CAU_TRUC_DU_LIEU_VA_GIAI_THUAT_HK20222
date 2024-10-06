
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int, int>
const int N = 5e5+5, M = 1e3+5, MOD = 1e9+7, inf = 1e18;
int test, n, m, x, y, res, k, cnt, nChain;
int child[N], ChainIn[N], HeadChain[N], num[N], par[N][17], h[N], tru[N];
vector<int> ke[N];

struct node{
    int val, lazy;
} t[N];

void down(int k) {
    t[k << 1].lazy += t[k].lazy;
    t[k << 1 | 1].lazy += t[k].lazy;
    t[k << 1].val += t[k].lazy;
    t[k << 1 | 1].val += t[k].lazy;
    t[k].lazy = 0;
}

void update(int k, int l, int r, int u, int v, int val) {
    if (r < u || l > v) return;
    if (l >= u && r <= v) {
        t[k].lazy += val;
        t[k].val += val;
        return;
    }
    int mid = (l + r) >> 1;
    down(k);
    update(k << 1, l, mid, u, v, val);
    update(k << 1 | 1, mid + 1, r, u, v, val);
}

int get(int k, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) return t[k].val;
    int mid = (l + r) >> 1;
    down(k);
    return get(k << 1, l, mid, u, v) + get(k << 1 | 1, mid + 1, r, u, v);
}

void getAns(int k, int l, int r) {
    if (l == r) {
        res = max(res, t[l].val - tru[l]);
        return;
    }
    int mid = (l + r) >> 1;
    down(k);
    getAns(k << 1, l, mid);
    getAns(k << 1 | 1, mid + 1, r);
}

void dfs(int u, int p) {
    child[u] = 1;
    for (auto v: ke[u]) if (v != p) {
        h[v] = h[u] + 1;
        par[v][0] = u;
        for (int i = 1; i <= 15; ++i) par[v][i] = par[par[v][i - 1]][i - 1];
        dfs(v, u);
        child[u] += child[v];
    }
}

int LCA(int u, int v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        k = h[u] - h[v];
        for (int i = 0; i <= 15; ++i)
            if (k & (1 << i)) u = par[u][i];
    }
    if (u == v) return u;
    for (int i = 15; i >= 0; --i)
        if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
    return par[u][0];
}

void HLD(int u, int p) {
    if (!HeadChain[nChain]) HeadChain[nChain] = u;
    ChainIn[u] = nChain;
    num[u] = ++cnt;
    int best = -1;
    for (auto v: ke[u]) if (v != p) {
        if (best == -1 || child[best] < child[v]) best = v;
    }
    if (best != -1) ++nChain, HLD(best, u);
    for (auto v: ke[u]) if (v != p && v != best) ++nChain, HLD(v, u);
}

void upquery(int u, int v) {
    while (1) {
        if (ChainIn[u] == ChainIn[v]) {
            update(1, 1, n, num[v], num[u], 1);
            break;
        }
        update(1, 1, n, num[HeadChain[ChainIn[u]]], num[u], 1);
        u = par[HeadChain[ChainIn[u]]][0];
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> test;
    for (int i = 1; i < n; ++i) cin >> x >> y, ke[x].push_back(y), ke[y].push_back(x);
    cnt = 0; dfs(1, 0);
    nChain = 1; HLD(1, 0);
    while (test--) {
        cin >> x >> y;
        int lca = LCA(x, y);
        upquery(x, lca);
        upquery(y, lca);
        ++tru[num[lca]];
//        update(1, 1, n, num[x], num[x], -1);
//        update(1, 1, n, num[y], num[y], -1);
    }
    //getAns(1, 1, n);
    for (int i = 1; i <= n; ++i) res = max(res, get(1, 1, n, i, i) - tru[i]);
    cout << res;
}
