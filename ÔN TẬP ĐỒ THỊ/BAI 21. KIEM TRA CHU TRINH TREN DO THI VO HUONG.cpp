#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};

int DFS(int u, int par){
	visited[u]=1;
	for(int i: ke[u]){
		if(visited[i]==0){
			if(DFS(i,u)){
				return 1;
			}
		} else if (i!=par) {
			return 1;//co canh nguoc
		}
	}
	return 0;
}
int main(){
	int dinh, canh;
	cin>>dinh>>canh;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
		ke[cuoi].push_back(dau);
	}
	for(int i=1;i<=dinh;i++){
		sort(ke[i].begin(),ke[i].end());
	}
	int check=0;
	for(int i=1;i<=dinh;i++){
		if(visited[i]==0){
			if(DFS(i,0)==1){
				check=1;
				break;
			}
		}
	}
	cout<<check;
}