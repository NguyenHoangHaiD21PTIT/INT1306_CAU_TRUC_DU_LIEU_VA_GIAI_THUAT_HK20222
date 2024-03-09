#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};

//2. Ham DFS tu dinh x
void DFS(int x){
	visited[x]=1;
	for(int i: ke[x]){//duyet cac dinh ke voi x
		if(visited[i]==0){
			DFS(i);
		}
	}
}
int main(){
	//1. Chuyen sang ds ke
	int dinh, canh;
	cin>>dinh>>canh;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
		ke[cuoi].push_back(dau);
	}
	//3. Dem so TPLT
	int dem=0;
	//Duyet cac dinh
	for(int i=1;i<=dinh;i++){
		if(visited[i]==0){
			dem++;
			DFS(i);
		}
	}
	cout<<dem;
}