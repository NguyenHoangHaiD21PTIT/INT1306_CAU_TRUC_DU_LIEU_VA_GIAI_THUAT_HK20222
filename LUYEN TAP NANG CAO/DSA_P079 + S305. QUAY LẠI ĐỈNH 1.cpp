#include <bits/stdc++.h>
using namespace std;

int vis[25], par[25];
vector<int> g[25];
set<int> s;

void BFS(int u){
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int w: g[v]){
            if(!vis[w]){
                q.push(w);
                par[w] = v;
                vis[w] = 1;
            }
        }
    }
}

void mark(int u, int v){
    memset(vis, 0, sizeof(vis));
    memset(par, 0, sizeof(par));
    BFS(u);
    while(v != u){
        s.insert(v);
        v = par[v];
    }
    s.insert(u);
}

int main(){
    int t; cin >> t;
    while(t--){
        s.clear();
        int n, m; 
        cin >> n >> m;
        for(int i = 1; i <= n; i++) g[i].clear();
        while(m--){
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
        }
        mark(1, 2); mark(2, 1);
        cout << s.size() << endl;
    }
}
