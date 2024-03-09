#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
int truoc[1005]={};

void DFS(int x){
	visited[x] = 1;
	for(int i: ke[x]){
		if(visited[i]==0){
			DFS(i);
			truoc[i]=x;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(visited,0,sizeof(visited));
		memset(truoc,0,sizeof(truoc));
		int dinh, canh, x, y;//x: dinh bat dau, y: dinh ket thuc
		cin>>dinh>>canh>>x>>y;
		for(int i=1;i<=dinh;i++) ke[i].clear();
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
		}
		DFS(x);
		if(visited[y]==0){
			cout<<-1;
		} else {
			vector<int>path;//dap an duong di
			while(y!=x){
				path.push_back(y);
				y = truoc[y];
			}
			path.push_back(x);
			for(int i = path.size()-1;i>=0;i--) cout<<path[i]<<" ";
		}
		cout<<endl;
	}
}