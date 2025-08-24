#include <bits/stdc++.h>
using namespace std;
const int MAX = 300300;
vector<int> adj[MAX];
int par[MAX], high[MAX];  
void DFS(int u) {
    for(int v : adj[u]) {
        if(v != par[u]) {
            par[v] = u;
            high[v] = high[u] + 1;
            DFS(v);
        }
    }
}
int LCA(int u, int v) {
    if(high[v] > high[u]) swap(v, u);//Đỉnh có độ sâu lớn hơn luôn nằm trước
    // Cân bằng độ sâu. Sau khi nâng đỉnh sâu hơn (B) lên bằng với đỉnh A. Nâng lên trùng A luôn thì cha là A
    while(high[u] > high[v]) u = par[u];
    if(u == v) return u;
    // Ngang nhau rồi thì cùng nhau đi lên
    while(u != v) {
        u = par[u];
        v = par[v];
    }
    return u; 
}
int main() {
    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1] = 0;  high[1] = 0; DFS(1); //Gốc thì đương nhiên không có thằng nào trên nó, độ cao là 0 luôn
    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        cout << LCA(x, y) << "\n";
    }
}

