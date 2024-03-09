#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
int truoc[1005]={};

void BFS(int x){
	queue<int>q;
	q.push(x);
	visited[x]=1;
	while(q.size()!=0){
		int p = q.front();
		q.pop();
		for(int i: ke[p]){
			if(visited[i]==0){
				q.push(i);
				truoc[i] = p;
				visited[i]=1;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(visited,0,sizeof(visited));
		memset(truoc,0,sizeof(truoc));
		int dinh, canh, x, y;
		cin>>dinh>>canh>>x>>y;
		for(int i=1;i<=dinh;i++) ke[i].clear();
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
		}
		BFS(x);
		if(visited[y]==0){
			cout<<-1;
		} else {
			vector<int>path;
			while(y!=x){
				path.push_back(y);
				y = truoc[y];
			}
			path.push_back(x);
			for(int i = path.size()-1;i>=0;i--){
				cout<<path[i]<<" ";
			}
		}
		cout<<endl;
	}
}
/* 1
6 9 1 6
1 2
2 5
3 1
3 2
3 5
4 3
5 4
5 6
6 4 */
