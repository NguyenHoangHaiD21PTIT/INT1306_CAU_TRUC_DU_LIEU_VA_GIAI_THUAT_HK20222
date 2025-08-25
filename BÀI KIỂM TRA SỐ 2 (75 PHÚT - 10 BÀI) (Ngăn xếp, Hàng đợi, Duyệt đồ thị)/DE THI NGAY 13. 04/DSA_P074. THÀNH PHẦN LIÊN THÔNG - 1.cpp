#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
int vis[1005];

void DFS(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) DFS(v);
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(s);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++;
            cout << i << "\n";
        }
    }
    if (cnt == 0) cout << 0;
}
