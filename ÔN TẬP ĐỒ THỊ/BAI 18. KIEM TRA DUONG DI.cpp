#include<bits/stdc++.h>
using namespace std;

int dem;//dem so TPLT
vector<int> ke[1005];
int visited[1005]={};
int TPLT[1005];// TPLT[y]=x tuc la y thuoc TPLT thu x. 
// Nhu vay u, v co duong di --> TPLT[u]=TPLT[v]

void DFS(int u){
	visited[u]=1;
	TPLT[u]=dem;
	for(int i: ke[u]){
		if(visited[i]==0){
			DFS(i);
		}
	}
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
	memset(visited,0,sizeof(visited));
	//1. Dem so TPLT va gan
	for(int i=1;i<=dinh;i++){
		if(visited[i]==0){
			dem++;
			DFS(i);
		}
	}
	int q;
	cin>>q;
	while(q--){
		memset(visited,0,sizeof(visited));
		int x, y;
		cin>>x>>y;
		if(TPLT[x]==TPLT[y]){
			cout<<1<<endl;
		} else {
			cout<<-1<<endl;
		}
	}
}