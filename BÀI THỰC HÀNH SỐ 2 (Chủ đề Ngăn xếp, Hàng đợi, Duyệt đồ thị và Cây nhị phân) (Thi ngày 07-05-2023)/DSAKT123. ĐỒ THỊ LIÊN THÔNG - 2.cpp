#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
int vis[1005];

void DFS(int u, int x, int y){
    vis[u] = 1;
    for(int i: g[u]){ //(i, u) = (x, y): Loại
        if((i == x && u == y) || (i == y && u == x)) continue;
        if(!vis[i]) DFS(i, x, y);
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        //memset(vis, 0, sizeof(vis));
        int n, m; cin >> n >> m;
        for(int i = 1; i <= n; i++) g[i].clear();
        vector<pair <int, int>>ed, res;
        while(m--){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            ed.push_back({u, v});
        }
        for(auto i: ed){
            memset(vis, 0, sizeof(vis));
            int cnt = 0, x = i.first, y = i.second;
            for(int j = 1; j <= n; j++){
                if(!vis[j]){
                    cnt++;
                    DFS(j, x, y);
                }
            }
            if (cnt > 1) res.push_back({x, y});
        }
        cout << res.size() << endl;
        for(auto i: res) cout << "(" << i.first << " " << i.second << ") ";
        cout << endl;
    }
}
