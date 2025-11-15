#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1005];
int vis[1005]={};

void BFS(int x){
	queue <int> q;
	q.push(x);
	vis[x] = 1;
	while(q.size()){
		int p = q.front();
		cout << p << " ";
		q.pop();
		for(int i: adj[p]){
			if(!vis[i]){
				q.push(i);
				vis[i] = 1;
			}
		}
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		int v, e, u;
		cin >> v >> e >> u;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= v; i++) adj[i].clear();
		while(e--){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
		}
		BFS(u); cout << endl;
	}
}
