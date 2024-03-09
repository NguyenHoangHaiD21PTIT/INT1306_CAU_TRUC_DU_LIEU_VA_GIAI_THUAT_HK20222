#include<bits/stdc++.h>
using namespace std;

int dem;//dem so TPLT
vector<int> ke[1005];
int visited[1005]={};
vector<int>lt[1005];//lt[i] la vector luu cac dinh trong tplt thu i

void DFS(int u){
	visited[u]=1;
	lt[dem].push_back(u);
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
	cout<<dem<<endl;
	for(int i=1;i<=dem;i++){
		cout<<lt[i].size()<<" ";
		sort(lt[i].begin(),lt[i].end());
		for(int j=0;j<lt[i].size()-1;j++){
			cout<<lt[i][j]<<" ";
		}
		cout<<lt[i][lt[i].size()-1];
		cout<<endl;
	}
}