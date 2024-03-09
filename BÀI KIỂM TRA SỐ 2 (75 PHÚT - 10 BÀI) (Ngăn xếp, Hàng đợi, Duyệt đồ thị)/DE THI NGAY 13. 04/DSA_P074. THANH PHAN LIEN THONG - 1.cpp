#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};

void DFS(int x){
	visited[x]=1;
	for(int i: ke[x]){
		if(visited[i]==0) DFS(i);
	}
}

int main(){
	int dinh, canh, v;
	cin>>dinh>>canh>>v;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
		ke[cuoi].push_back(dau);
	}
	DFS(v);
	int cnt=0;
	for(int i=1;i<=dinh;i++){
		if(visited[i]==0){
			cnt++;
			cout<<i<<endl;
		}
	}
	if(cnt==0) cout<<0<<endl;
}