#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1005];
int vis[1005];

void DFS(int x){
    vis[x] = 1;
    for (int i: adj[x]){
        if (!vis[i]) DFS(i);
    }
}

int main(){
    int n, m; cin >> n >> m;
    while (m--){
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1);
    int check = 0;
    for (int i = 2; i <= n; i++){
        if (!vis[i]){
            check = 1;
            cout << i << endl;
        }
    }
    if (!check) cout << 0;
}
