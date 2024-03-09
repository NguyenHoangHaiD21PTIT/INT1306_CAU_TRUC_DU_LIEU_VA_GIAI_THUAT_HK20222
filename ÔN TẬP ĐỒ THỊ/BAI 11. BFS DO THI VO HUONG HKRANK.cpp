#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];

int visited[1005]={};

void BFS(int x){//BFS tu dinh x
	//Buoc 1: khoi tao
	queue<int>q;
	q.push(x);
	visited[x]=1;
	//Buoc 2: Lap khi ngan xep chua rong
	while(q.size()!=0){
		//a. Luu tru phan tu dau qe va xoa pt nay
		int x = q.front();
		cout<<x<<" ";
		q.pop();
		//b. Xet cac phan tu ke voi x
		for(int i=0;i<ke[x].size();i++){
			if(visited[ke[x][i]]==0){
				visited[ke[x][i]]=1;
				q.push(ke[x][i]);
			}
		}
	}
}
int main(){
	int dinh, canh, v;//v: dinh bat dau duyet
	cin>>dinh>>canh>>v;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
		ke[cuoi].push_back(dau);
	}
	for(int i=1;i<=dinh;i++){
		sort(ke[i].begin(),ke[i].end());
	}
	BFS(v);
}