#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 200005;
vector<int> adj[MAXN];
ll C[MAXN];
ll dp[MAXN][2]; 

void dfs(int u, int par) {
    dp[u][0] = 0;
    dp[u][1] = C[u];
    for (int v : adj[u]) {
        if (v == par) continue; 
        dfs(v, u); 
        dp[u][0] += max(dp[v][0], dp[v][1]); 
        dp[u][1] += dp[v][0]; 
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> C[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0); 
    cout << max(dp[1][0], dp[1][1]);
}
