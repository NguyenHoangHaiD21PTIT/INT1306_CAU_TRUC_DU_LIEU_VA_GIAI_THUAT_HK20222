#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1005];
int col[1005], par[1005];

bool DFS (int x){
    col[x] = 1;
    for (int i: adj[x]){
        if (!col[i]){
            par[i] = x;
            if (DFS(i)) return true;
        } else if (col[i] == 1) return true;
    }
    col[x] = 2;
    return false;
}

int main(){
    int t; cin >> t;
    while (t--){
        memset (col, 0, sizeof(col));
        memset (par, 0, sizeof(par));
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) adj[i].clear();
        while (m--){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        string ans = "NO";
        for(int i = 1; i <= n; i++){
            if (!col[i]){
                if (DFS(i)){
                    ans = "YES";
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}
