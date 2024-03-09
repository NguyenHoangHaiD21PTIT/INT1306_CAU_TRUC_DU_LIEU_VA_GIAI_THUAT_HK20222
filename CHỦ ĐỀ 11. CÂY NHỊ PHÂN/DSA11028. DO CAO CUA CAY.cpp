#include<bits/stdc++.h>
using namespace std;

int visited[100005];
vector<int>ke[100005];
int ans = 0;

void DFS(int u, int h){
	ans = max(ans, h);
	visited[u] = 1;
	for(int i: ke[u]){
		if(visited[i]==0) DFS(i, h+1);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int dinh;
		cin>>dinh;
		int canh = dinh - 1;
		ans = 0;
		for(int i = 1;i<=dinh;i++) ke[i].clear();
		memset(visited, 0, sizeof(visited));
		while(canh--){
			int x, y;
			cin>>x>>y;
			ke[x].push_back(y);
			ke[x].push_back(y);
		}
		DFS(1, 0);
		cout<<ans<<endl;
	}
}