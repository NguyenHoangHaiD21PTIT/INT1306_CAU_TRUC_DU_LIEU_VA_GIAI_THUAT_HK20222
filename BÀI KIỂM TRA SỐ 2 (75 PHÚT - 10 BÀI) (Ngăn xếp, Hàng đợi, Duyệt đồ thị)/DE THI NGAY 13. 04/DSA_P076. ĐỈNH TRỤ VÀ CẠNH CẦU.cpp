#include <bits/stdc++.h>
using namespace std;

vector<int> g[1005];
int vis[1005];
vector<pair<int,int>> ed;

void DFS1(int u) { 
    vis[u] = 1;
    for(int v : g[u]){
        if(!vis[v]) DFS1(v);
	}
}

void DFS2(int u, int x, int y) { 
    vis[u] = 1;
    for(int v : g[u]) {
        if((u == x && v == y) || (u == y && v == x)) continue;
        if(!vis[v]) DFS2(v, x, y);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ed.push_back({u, v});
    }
    int orig_cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]) { 
			DFS1(i); 
			orig_cnt++; 
		}
	}
    int tru = 0;
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        vis[i] = 1;
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(!vis[j]) { 
				DFS1(j); 
				cnt++; 
			}	
		}
		if(cnt > orig_cnt) tru++;
    }
    int cau = 0;
    for(auto e : ed) {
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        int x = e.first, y = e.second;
        for(int j = 1; j <= n; j++){
            if(!vis[j]) { 
				DFS2(j, x, y); 
				cnt++; 
			}
		}
		if(cnt > orig_cnt) cau++;
    }
    cout << tru << " " << cau;
}
