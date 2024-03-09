#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];// luu ds ke ban dau
vector<int>daoke[1005];// luu ds ke nguoc
stack<int>topo;
int visited[1005]={};

void DFS1(int x){
	visited[x]=1;
	for(int i: ke[x]){
		if(visited[i]==0){
			DFS1(i);
		}
	}
	cout<<x<<" ";
	topo.push(x);
}

void DFS2(int x){
	visited[x]=1;
	cout<<x<<" ";
	for(int i: daoke[x]){
		if(visited[i]==0){
			DFS2(i);
		}
	}
}
int main(){
	int dinh, canh;
	cin>>dinh>>canh;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);//luu ds ke do thi ban dau
		daoke[cuoi].push_back(dau);//luu d ke do thi dao nguoc
	}
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=dinh;i++){
		if(visited[i]==0){
			DFS1(i);
		}
	}
	cout<<endl;
	memset(visited,0,sizeof(visited));
	while(topo.size()!=0){
		int x = topo.top();
		topo.pop();
		if(visited[x]==0){
			DFS2(x);
			cout<<endl;
		}
	}
}
/*
8 9
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 8
8 6
*/