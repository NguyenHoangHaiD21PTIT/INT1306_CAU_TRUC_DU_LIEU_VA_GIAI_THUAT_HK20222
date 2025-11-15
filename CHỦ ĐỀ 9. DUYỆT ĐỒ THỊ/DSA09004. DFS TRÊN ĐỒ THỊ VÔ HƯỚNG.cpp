#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1005];
int vis[1005] = {};

void DFS(int x){
	vis[x] = 1;
	cout << x << " ";
	for(int i: adj[x]){
		if(!vis[i]) DFS(i);
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		memset(vis, 0, sizeof(vis));
		int v, e, u;
		cin >> v >> e >> u;
		for(int i = 1;i <= v; i++) adj[i].clear();
		while(e--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		DFS(u);
		cout << endl;
	}
}
