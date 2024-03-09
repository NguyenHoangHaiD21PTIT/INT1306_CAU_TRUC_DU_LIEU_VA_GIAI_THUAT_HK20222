#include<bits/stdc++.h>
using namespace std;

vector<int>ke[20005];
int visited[20005]={};

void DFS(int x){
	visited[x]=1;
	for(int i: ke[x]){
		if(visited[i]==0) DFS(i);
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
	for(int i=1;i<=dinh;i++){
		memset(visited,0, sizeof(visited));
		int cnt = 0;
		visited[i] = 1;
		for(int j = 1;j<=dinh;j++){
			if(visited[j]==0){
				cnt++;
				DFS(j);
			}
		}
		cout<<cnt<<endl;
	}
	
}