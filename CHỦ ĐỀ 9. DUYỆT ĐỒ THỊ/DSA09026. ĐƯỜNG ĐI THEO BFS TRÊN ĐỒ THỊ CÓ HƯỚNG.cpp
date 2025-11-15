#include<bits/stdc++.h>
using namespace std;

vector <int> adj[1005];
int vis[1005] = {}, par[1005] = {};

void BFS(int x){
	queue<int>q;
	q.push(x);
	vis[x] = 1;
	while(q.size()){
		int p = q.front();
		q.pop();
		for(int i: adj[p]){
			if(!vis[i]){
				q.push(i);
				par[i] = p;
				vis[i] = 1;
			}
		}
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		memset(vis, 0, sizeof(vis));
		memset(par, 0, sizeof(par));
		int v, e, x, y;
		cin >> v >> e >> x >> y;
		for(int i = 1;i <= v; i++) adj[i].clear();
		while(e--){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}
		BFS(x);
		if(!vis[y]) cout << -1;
		else {
			vector <int> path;
			while(y != x){
				path.push_back(y);
				y = par[y];
			}
			path.push_back(x);
			for(int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
		}
		cout << endl;
	}
}
