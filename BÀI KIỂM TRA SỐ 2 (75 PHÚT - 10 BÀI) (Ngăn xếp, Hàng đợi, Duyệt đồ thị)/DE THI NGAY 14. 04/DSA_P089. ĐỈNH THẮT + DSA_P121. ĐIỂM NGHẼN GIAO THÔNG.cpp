#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> adj[MAXN];
int vis[MAXN];

void DFS(int u) {
    vis[u] = 1;
    for (int v : adj[u]){
        if (!vis[v]) DFS(v);
	}
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        for (int i = 1; i <= n; i++) adj[i].clear();
        while (m--) {
            int u, v; 
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int ans = 0;
        for (int ban = 1; ban <= n; ban++) {
            memset(vis, 0, sizeof(vis));
            vis[ban] = 1;  
            DFS(s);
            if (!vis[t]) ans++;
        }
        cout << ans << "\n";
    }
}
