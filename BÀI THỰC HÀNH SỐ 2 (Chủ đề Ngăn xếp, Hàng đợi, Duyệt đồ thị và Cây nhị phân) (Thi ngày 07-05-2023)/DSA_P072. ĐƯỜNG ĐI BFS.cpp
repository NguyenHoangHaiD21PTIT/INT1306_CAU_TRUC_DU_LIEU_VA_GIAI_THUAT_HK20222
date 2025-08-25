#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int vis[1005], pre[1005];

void BFS(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                pre[v] = u;
                vis[v] = 1;
            }
        }
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        memset(vis, 0, sizeof(vis));
        memset(pre, 0, sizeof(pre));
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        for (int i = 1; i <= n; i++) adj[i].clear();
        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
        BFS(s);
        if (!vis[t]) cout << -1;
        else {
			vector<int> path;
			while(t != s){
				path.push_back(t);
				t = pre[t];
			}
			path.push_back(s);
			reverse(path.begin(), path.end());
			for (int v : path) cout << v << " ";
		}
        cout << "\n";
    }
}
