#include <bits/stdc++.h>
using namespace std;
vector<int> g[20005];
int vis[20005] = {};
void dfs(int u){
    vis[u] = 1;
    for(int v : g[u]){
        if(!vis[v]) dfs(v);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        vis[i] = 1;
        for(int j = 1; j <= n; j++){
            if(!vis[j]){
                cnt++;
                dfs(j);
            }
        }
        cout << cnt << endl;
    }
}
//Máy chấm: Lúc 7/7, lúc 6/7 (TLE)??
