#include <bits/stdc++.h>
using namespace std;

int d[1005][1005];
vector<int> adj[1005]; 

void DFS(int start, int u, int depth) {
    d[start][u] = depth;
    for (int v : adj[u]) {
        if (d[start][v] == -1) DFS(start, v, depth + 1);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i)  adj[i].clear();

        for (int i = 1; i <= n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) d[i][j] = -1;
        }

        for (int i = 1; i <= n; ++i) DFS(i, i, 0);

        int q;
        cin>>q;
        while(q--){
            int u, v;
            cin>>u>>v;
            cout<<d[u][v]<<endl;
        }

    }

    return 0;
}