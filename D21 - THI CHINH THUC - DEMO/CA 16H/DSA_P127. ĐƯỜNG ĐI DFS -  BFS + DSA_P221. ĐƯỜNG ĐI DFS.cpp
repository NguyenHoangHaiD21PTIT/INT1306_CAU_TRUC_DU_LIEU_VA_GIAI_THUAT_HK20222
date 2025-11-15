#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int vis[1005], par[1005];

void DFS(int u) {
    vis[u] = 1;
    for(int v: adj[u]) {
        if(!vis[v]) {
            par[v] = u;
            DFS(v);
        }
    }
}

void BFS(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: adj[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

void pr(int s, int t, bool useDFS) {
    memset(vis, 0, sizeof(vis));
    memset(par, 0, sizeof(par));
    if(useDFS) DFS(s);
    else BFS(s);
    if(!vis[t]) {
        cout << "-1\n";
        return;
    }
    vector<int> path;
    int cur = t;
    while(cur != s) {
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    for(int v: path) cout << v << " ";
    cout << "\n"; 
}

int main() {
    int V, E;
    cin >> V >> E;
    while(E--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 2; i <= V; i++) {
        pr(1, i, true);  
        pr(i, 1, false);
    }
    return 0;
}
