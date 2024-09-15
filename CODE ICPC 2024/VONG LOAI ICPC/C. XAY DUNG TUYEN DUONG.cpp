#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int,int>
#define pb push_back
const int N = 1e6+5, M = 1e3+1, inf = 1e18, MOD = 1e9+7;
int test, n, m, x, y, res, k, cnt, sum, block;
int a[N], vis[N], f[N], vt[N];
vector<int> ke[N], adj[N];

void dfs(int u) {
    vt[u] = cnt;
    vis[u] = 1;
    for (auto v : ke[u]) if (!vis[v]) dfs(v);
}

int bfs(int s, int t) {
    queue<int> q;
    while (q.size()) q.pop();
    q.push(s);
    for (int i = 1; i <= n; ++i) vis[i] = 0, f[i] = 0;
    vis[s] = 1; f[s] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (auto v: adj[u]) if (!vis[v]) {
            f[v] = f[u] + 1;
            vis[v] = 1;
            q.push(v);
        }
        if (f[t]) break;
    }
    return f[t];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) ke[i].clear(), adj[i].clear(), vis[i] = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        ke[x].pb(y);
        ke[y].pb(x);
    }
    cnt = 0;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        ++cnt;
        dfs(i);
    }
    for (int i = 2; i <= n; ++i) {
        if (vt[i] != vt[i - 1]) {
            adj[vt[i - 1]].pb(vt[i]);
            adj[vt[i]].pb(vt[i - 1]);
        }
    }
    cout << bfs(vt[1], vt[n]) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> test;
    while (test--) solve();
}
