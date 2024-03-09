#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};

void DFS(int x){
	visited[x]=1;
	for(int i: ke[x]){
		if(visited[i]==0){
			DFS(i);
		}
	}
}
int main(){
	int dinh, canh;
	cin>>dinh>>canh;
	int x = dinh - canh;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
		ke[cuoi].push_back(dau);
	}
	int check;
	if(x!=1){
		check = 0;
	} else {
		for(int i=1;i<=dinh;i++){
			sort(ke[i].begin(),ke[i].end());
		}
		int cnt = 0;
		memset(visited,0,sizeof(visited));
		for(int i=1;i<=dinh;i++){
			if(visited[i]==0){
				DFS(i);
				cnt++;
			}
		}
		if(cnt!=1){
			check = 0;
		} else {
			check = 1;
		}
	}
	cout<<check;
}