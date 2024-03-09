#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
vector<pair<int,int>>dscanh;

void DFS(int x){
	visited[x]=1;
	for(int i: ke[x]){
		if(visited[i]==0) DFS(i);
	}
}

void DFS2(int u, int x, int y){//Loang tu dinh u nhung loai canh (x,y)
	visited[u]=1;
	for(int i: ke[u]){
		//(i,u)=(x,y)--> Loai
		if((i==x&&u==y)||(i==y&&u==x)) continue;
		if(visited[i]==0) DFS2(i,x,y);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(visited,0,sizeof(visited));
		int dinh, canh;
		cin>>dinh>>canh;
		dscanh.clear();
		for(int i=1;i<=dinh;i++) ke[i].clear();
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
			dscanh.push_back({dau,cuoi});
		}
		for(auto i: dscanh){
			memset(visited,0,sizeof(visited));
			int cnt = 0;
			int x = i.first;
			int y = i.second;
			for(int j = 1;j<=dinh;j++){
				if(visited[j]==0){
					cnt++;
					DFS2(j,x,y);
				}
			}
			if(cnt>1) cout<<x<<" "<<y<<" ";
		}
		cout<<endl;
	}
}