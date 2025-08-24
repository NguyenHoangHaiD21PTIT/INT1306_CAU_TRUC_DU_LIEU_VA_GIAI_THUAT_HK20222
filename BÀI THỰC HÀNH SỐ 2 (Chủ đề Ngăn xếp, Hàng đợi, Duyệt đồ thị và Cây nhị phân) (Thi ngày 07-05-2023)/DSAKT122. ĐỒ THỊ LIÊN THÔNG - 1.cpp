#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
int vis[1005];

void DFS(int x){
    vis[x] = 1;
    for(int y : g[x]){
        if(!vis[y]) DFS(y);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        memset(vis, 0, sizeof(vis));
        int n, m; cin >> n >> m;
        for(int i = 1; i <= n; i++) g[i].clear();
        while(m--){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector <int> res;
        for(int i = 1; i <= n; i++){
            memset(vis, 0, sizeof(vis));
            vis[i] = 1; 
            int c = 0;
            for(int j = 1; j <= n; j++){
                if(!vis[j]){
                    c++;
                    DFS(j);
                }
            }
            if(c > 1) res.push_back(i);
        }
        cout << res.size() << endl;
        for(int x: res) cout << x << " ";
        cout << endl;
    }
}
