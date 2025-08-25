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
                vis[v] = 1;
                pre[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, s;
        cin >> n >> m >> s;
        for (int i = 1; i <= n; i++) adj[i].clear();
        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (i == s) continue;
            memset(vis, 0, sizeof(vis));
            memset(pre, 0, sizeof(pre));
            BFS(s);
            if (!vis[i]) cout << "No path\n";
            else {
                vector<int> path;
                int cur = i;
                while (cur != s) {   
                    path.push_back(cur);
                    cur = pre[cur];
                }
                path.push_back(s);
                reverse(path.begin(), path.end());
                for (int x : path) cout << x << " ";
                cout << "\n";
            }
        }
    }
}
