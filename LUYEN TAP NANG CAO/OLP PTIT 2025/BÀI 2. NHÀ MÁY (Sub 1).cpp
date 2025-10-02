#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> s, c;
vector<vector<int>> g;

pair<int,int> get(int u, int v) {
    vector<int> par(n + 1, -1);
    queue<int> q;
    q.push(u);
    par[u] = u;
    while (!q.empty()) {
        int x = q.front(); 
        q.pop();
        for (int nxt : g[x]) {
            if (par[nxt] == -1) {
                par[nxt] = x;
                q.push(nxt);
            }
        }
    }
    vector<int> path;
    int cur = v;
    while (cur != par[cur]) {
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(u);
    reverse(path.begin(), path.end());
    int sum = 0, gd = 0;
    for (int node: path) {
        sum += s[node];
        gd = gcd(gd, c[node]);
    }
    return {sum, gd};
}

int main() {
    cin >> n;
    s.resize(n + 1); c.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    g.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = INT_MIN;
    for (int x = 1; x <= n; x++)
        for (int y = x + 1; y <= n; y++)
            for (int z = y + 1; z <= n; z++) {
                auto [dxy, gxy] = get(x, y);
                auto [dyz, gyz] = get(y, z);
                auto [dzx, gzx] = get(z, x);
                int G = gcd(gcd(gxy, gyz), gzx);
                if (G > 1) ans = max(ans, dxy + dyz + dzx);
            }
    if (ans == INT_MIN) cout << "No Solution";
    else cout << ans;
}
