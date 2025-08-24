#include <bits/stdc++.h>
using namespace std;

vector<int> g[10005], gr[10005]; // gr = graph reversed
int vis[10005];
stack<int> st;

void dfs1(int u) { //Tạo thứ tự sắp xếp Topo trong Stack
    vis[u] = 1;
    for(int v : g[u]){
        if(!vis[v]) dfs1(v);
	}
    st.push(u);
}

void dfs2(int u) { //DFS trên đồ thị đảo
    vis[u] = 1;
    for(int v : gr[u]){
        if(!vis[v]) dfs2(v);
	}
}

int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u); 
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs1(i);
	}
    memset(vis, 0, sizeof(vis));
    int scc = 0;
    while(!st.empty()) {
        int u = st.top(); st.pop();
        if(!vis[u]) {
            scc++;
            dfs2(u);
        }
    }
    cout << scc << endl;
}
