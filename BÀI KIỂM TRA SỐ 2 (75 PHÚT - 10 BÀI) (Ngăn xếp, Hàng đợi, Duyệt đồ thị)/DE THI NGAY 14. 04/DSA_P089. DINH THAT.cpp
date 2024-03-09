#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005];

void DFS(int x){
	visited[x] = 1;
	for(int i: ke[x]){
		if(visited[i]==0) DFS(i);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int v, e, a, b;
		cin>>v>>e>>a>>b;
		for(int i = 1;i<=v;i++) ke[i].clear();
		while(e--){
			int x, y;
			cin>>x>>y;
			ke[x].push_back(y);
		}
		int cnt = 0;
		for(int i=1;i<=v;i++){
			memset(visited, 0, sizeof(visited));
			visited[i] = 1;
			DFS(a);
			if(visited[b]==0) cnt++;
		}
		cout<<cnt<<endl;
	}
}