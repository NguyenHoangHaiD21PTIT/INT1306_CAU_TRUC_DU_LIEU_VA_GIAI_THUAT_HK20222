#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> s, c;
vector<vector<int>> adj;
int d[5005][5005];  // tổng s trên đường
int g[5005][5005];  // GCD c trên đường

// BFS từ u để tính d[u][v] và g[u][v] cho tất cả v
void bfs(int u) {
    vector<int> par(n + 1, -1);
    queue<int> q;
    q.push(u);
    par[u] = u;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        int sum = 0, gd = 0;
        int cur = x;
        while (cur != par[cur]) { 
            sum += s[cur]; 
            gd = gcd(gd, c[cur]); 
            cur = par[cur]; 
        }
        sum += s[u]; gd = gcd(gd, c[u]);
        d[u][x] = sum;
        g[u][x] = gd;
        for (int v : adj[x]) {
            if (par[v] == -1) {
                par[v] = x;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n;
    s.resize(n + 1); c.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    adj.assign(n + 1, {});
    for (int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) bfs(i);
    int ans = INT_MIN;
    for (int x = 1; x <= n; x++){
        for (int y = x+1; y <= n; y++){
            for (int z = y+1; z <= n; z++) {
                int G = gcd(g[x][y], gcd(g[y][z], g[z][x]));
                if (G > 1) ans = max(ans, d[x][y] + d[y][z] + d[z][x]);
            }
        }
    }
    if (ans == INT_MIN) cout << "No Solution";
    else cout << ans;
}
