#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005];
int par[1005];

bool DFS(int x){
	visited[x] = 1;
	for(int i: ke[x]){
		if(visited[i]==0){
			par[i] = x;;
			if(DFS(i)) return true;
		} else if (i!=par[x]){
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(visited, 0, sizeof(visited));
		memset(par, 0, sizeof(par));
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
		int check = 0;
		for(int i=1;i<=dinh;i++){
			if(visited[i]==0){
				if(DFS(i)){
					check = 1;
					break;
				}
			}
		}
		if(check) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}