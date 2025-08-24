#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
int vis[1005];

void DFS(int u) {
    vis[u] = 1;
    for (int v : g[u]){
        if (!vis[v]) DFS(v);
	}
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m; 
        cin >> n >> m;
        for (int i = 1; i <= n; i++) g[i].clear();
        while (m--) {
            int u, v; 
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = -1, best = 1;
        for (int x = 1; x <= n; x++) {
            memset(vis, 0, sizeof(vis));
            vis[x] = 1; 
            int comp = 0;
            for (int i = 1; i <= n; i++){
                if (!vis[i]) { 
					DFS(i); 
					comp++; 
				}
			}
            if (comp > best) {
                best = comp;
                ans = x;
            }
        }
		if (ans == -1) cout << 0 << "\n";
		else cout << ans << "\n";
    }
}
