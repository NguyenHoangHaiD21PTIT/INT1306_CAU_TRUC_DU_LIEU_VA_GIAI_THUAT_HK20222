#include <bits/stdc++.h>
using namespace std;

vector <int> g[100005], gr[100005]; //g: Đồ thị đúng, gr: Đồ thị đảo
int vis[100005];
stack <int> st;

void DFS1 (int u){ //Tạo thứ tự sắp xếp topo trong stack
    vis[u] = 1;
    for (int v: g[u]){
        if (!vis[v]) DFS1(v);
    }
    st.push(u);
}

void DFS2 (int u){
    vis[u] = 1;
    for (int v: gr[u]){
        if (!vis[v]) DFS2(v);
    }
}

int main(){
    int n, m; 
    cin >> n >> m;
    while (m--){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        gr[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]) DFS1(i);
    }
    memset (vis, 0, sizeof(vis));
    int cnt = 0;
    while (!st.empty()){
        int u = st.top(); st.pop();
        if (!vis[u]){
            cnt++;
            DFS2(u);
        }
    }
    cout << cnt;
}
