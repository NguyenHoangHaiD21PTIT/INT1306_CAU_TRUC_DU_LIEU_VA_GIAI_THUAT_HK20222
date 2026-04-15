#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
vector<int> adj[MAX];
bool vis[MAX];
int par[MAX];
vector<int> ans;

void dfs(int u) {
    vis[u] = true;
    ans.push_back(u);
    for (int v: adj[u]) {
        if (!vis[v]) {
            par[v] = u;
            dfs(v);
        }
    }
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    ans.clear();
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
        par[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(s);
    if (ans.size() < n) cout << -1 << "\n";
    else {
        for (int i = 1; i < ans.size(); i++) cout << par[ans[i]] << " " << ans[i] << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
