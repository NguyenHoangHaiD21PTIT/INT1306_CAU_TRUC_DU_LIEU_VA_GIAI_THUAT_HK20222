#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
bool vis[1005];
int id[1005], c;//id[x] = y: Đỉnh x thuộc thành phần liên thông thứ i, c: Số thành phần liên thông

void dfs(int u) {
    vis[u] = true;
    id[u] = c;
    for (int v: g[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        c = 0; 
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; i++) g[i].clear();
        while (m--) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                c++;
                dfs(i);
            }
        }
        int q; cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            if (id[u] == id[v]) cout << "YES\n";
            else cout << "NO\n";  
        }
    }
}
