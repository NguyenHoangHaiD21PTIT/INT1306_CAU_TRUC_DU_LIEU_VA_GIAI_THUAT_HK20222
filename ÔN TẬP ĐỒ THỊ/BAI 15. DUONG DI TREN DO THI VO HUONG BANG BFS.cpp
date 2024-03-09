#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
int truoc[1005]={};

void BFS(int u){
	queue<int>q;
	q.push(u);
	visited[u]=1;
	while(q.size()!=0){
		int x = q.front();
		q.pop();
		for(int i: ke[x]){
			if(visited[i]==0){
				q.push(i);
				visited[i]=1;
				truoc[i]=x;
			}
		}
	}
}
int main(){
	int dinh, canh,x,y;
	cin>>dinh>>canh>>x>>y;
	while(canh--){
		int dau, cuoi;
		cin>>dau>>cuoi;
		ke[dau].push_back(cuoi);
		ke[cuoi].push_back(dau);
	}
	for(int i=1;i<=dinh;i++){
		sort(ke[i].begin(), ke[i].end());
	}
	memset(visited, 0, sizeof(visited));
	BFS(x);
	if(visited[y]==0){
		cout<<-1;
	} else {
		vector<int>path;
		while(y!=x){
			path.push_back(y);
			y=truoc[y];
		}
		path.push_back(x);
		for(int i=path.size()-1;i>=0;i--){
			cout<<path[i]<<" ";
		}
	}
}