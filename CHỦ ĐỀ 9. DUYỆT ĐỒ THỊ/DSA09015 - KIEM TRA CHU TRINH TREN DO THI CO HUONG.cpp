#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int color[1005];
int par[1005];

bool DFS(int x){
	color[x] = 1;//visited[x]=1
	for(int i: ke[x]){
		if(color[i]==0){ //visited[i] = 0
			par[i] = x;
			if(DFS(i)) return true;
		} else if (color[i]==1) return true;
	}
	color[x] = 2;
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(color,0,sizeof(color));
		memset(par,0,sizeof(par));
		int dinh, canh;
		cin>>dinh>>canh;
		for(int i=1;i<=dinh;i++) ke[i].clear();
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
		}
		int check = 0;
		for(int i=1;i<=dinh;i++){
			if(color[i]==0){ //visited[i]==0
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