#include<bits/stdc++.h>
using namespace std;

int dem;//dem so TPLT
vector<int> ke[1005];
int visited[1005]={};
set<int>lt[1005];//lt[i] la vector luu cac dinh trong tplt thu i

void DFS(int u){
	visited[u]=1;
	lt[dem].insert(u);
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
	
	//2. Push cac dinh be nhat cua tung TPLT vao 1 vector
	vector<int>v;
	for(int i=1;i<=dem;i++) v.push_back(*lt[i].begin());
	cout<<dem-1<<endl;
	for(int i=0;i<v.size()-1;i++) cout<<v[i]<<" "<<v[i+1]<<endl;
}