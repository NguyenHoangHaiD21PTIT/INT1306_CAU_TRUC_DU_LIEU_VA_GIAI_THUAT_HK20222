#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
vector<int>tplt[1005]={};
int cntgoc = 0;//so tplt goc

void DFS(int x){
	visited[x]=1;
	tplt[cntgoc].push_back(x);
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
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=dinh;i++){
		if(visited[i]==0){
			cntgoc++;
			DFS(i);
		}
	}
	vector<int>ans;
	for(int i=1;i<=dinh;i++){
		ans.push_back(tplt[i].size());
	}
	cout<<*max_element(ans.begin(),ans.end());
}