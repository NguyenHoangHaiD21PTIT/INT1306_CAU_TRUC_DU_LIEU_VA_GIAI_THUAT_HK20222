#include<bits/stdc++.h>
using namespace std;

int visited[1005];
vector<int>ke[1005];
vector<int>leaf;
int par[1005];

void DFS(int u){
	visited[u] = 1;
	int check = 0;
	for(int i: ke[u]){
		if(visited[i]==0){
			check = 1;
			DFS(i);
			par[i] = u;
		}
	}
	if(!check) leaf.push_back(u);
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int dinh;
		cin>>dinh;
		int canh = dinh - 1;
		for(int i = 1;i<=dinh;i++) ke[i].clear();
		memset(visited, 0, sizeof(visited));
		memset(par, 0, sizeof(par));
		leaf.clear();
		while(canh--){
			int x, y;
			cin>>x>>y;
			ke[x].push_back(y);
			ke[x].push_back(y);
		}
		DFS(1);
		sort(leaf.begin(), leaf.end());
		for(int i: leaf){
			vector<int>path;
			int tmp = i;
			cout<<endl;
			while(tmp!=1){
				path.push_back(tmp);
				tmp = par[tmp];
			}
			path.push_back(1);
			reverse(path.begin(), path.end());
			for(auto x: path) cout<<x<<" ";
			cout<<endl;
		}
	}
}