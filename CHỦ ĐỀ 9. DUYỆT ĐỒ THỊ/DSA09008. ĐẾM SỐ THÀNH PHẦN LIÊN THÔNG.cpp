#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; 
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            vis[i] = false; 
        }
        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
                ans++;
            }
        }
        cout << ans << "\n";
	}		
}
