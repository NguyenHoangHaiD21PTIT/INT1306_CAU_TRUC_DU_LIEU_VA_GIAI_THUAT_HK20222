#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005];
int st, en;
int par[1005];

bool DFS(int v){
	visited[v] = 1;
	for(int i: ke[v]){
		if(visited[i]==0){
			par[i] = v;
			if(DFS(i)) return true;
		} else if (i!=par[v]&&i==1){
			st = i; en = v;
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int check = 0;
		memset(visited,0,sizeof(visited));
		memset(par,0,sizeof(par));
		int dinh, canh;
		cin>>dinh>>canh;
		for(int i=1;i<=dinh;i++) ke[i].clear();
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
		}
		for(int i=1;i<=dinh;i++) sort(ke[i].begin(),ke[i].end());
		if(DFS(1)){
			vector<int>path;
			path.push_back(st);
			while(en!=st){
				path.push_back(en);
				en = par[en];
			}
			path.push_back(st);
			reverse(path.begin(),path.end());
			for(auto i: path) cout<<i<<" ";
		} else {
			cout<<"NO";
		}
		cout<<endl;
	}
}