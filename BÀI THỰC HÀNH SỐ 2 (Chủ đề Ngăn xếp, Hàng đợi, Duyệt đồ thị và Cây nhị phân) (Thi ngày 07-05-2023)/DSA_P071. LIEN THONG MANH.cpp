//THUAT TOAN KOSARAJU KIEM TRA TINH LIEN THONG MANH
#include<bits/stdc++.h>
using namespace std;

vector<int>ke[10005];
vector<int>daoke[10005];//dao chieu cac cung cua do thi
int visited[10005]={};
stack<int>topo;//thu tu sap xep topo

//Buoc 1: Tao thu tu sap xep topo
void DFS(int x){
	visited[x]=1;
	for(int i: ke[x]){
		if(visited[i]==0){
			DFS(i);
		}
	}
	topo.push(x);
}

void DFS2(int x){
	visited[x]=1;
	for(int i: daoke[x]){
		if(visited[i]==0){
			DFS2(i);
		}
	}
}
int main(){
	memset(visited,0,sizeof(visited));
	int dinh, canh;
	cin>>dinh>>canh;
	for(int i=1;i<=dinh;i++){
		ke[i].clear();
		daoke[i].clear();
	}
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
		daoke[cuoi].push_back(dau);//Buoc 2: Xay dung do thi "nguoc"
	}	
	for(int i=1;i<=dinh;i++){
		if(visited[i]==0){
			DFS(i);
		}
	}
	int cnt = 0;//so tplt manh
	memset(visited,0,sizeof(visited));
	//Buoc 3: Pop lan luot stack topo ra, cai nao chua xet thi loang het co va tang so tplt len
	while(topo.size()!=0){
		int x = topo.top();
		topo.pop();
		if(visited[x]==0){
			cnt++;
			DFS2(x);
		}
	}
	cout<<cnt<<endl;
}
		
		