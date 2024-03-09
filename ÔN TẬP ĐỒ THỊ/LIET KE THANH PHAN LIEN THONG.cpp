#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
vector<int>tplt[1005];
int cnt;//so tplt toan do thi

void DFS(int x){
	visited[x]=1;
	tplt[cnt].push_back(x);
	for(int i: ke[x]){
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
	for(int i=1;i<=dinh;i++){
		sort(ke[i].begin(), ke[i].end());
	}
	memset(visited,0,sizeof(visited));
	int cnt=0;//so TPLT
	for(int i=1;i<=dinh;i++){
		if(visited[i]==0){
			cnt++;
			DFS(i);
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		for(int j=0;j<tplt[i].size();j++){
			cout<<tplt[i][j]<<" ";
		}
		cout<<endl;
	}
}