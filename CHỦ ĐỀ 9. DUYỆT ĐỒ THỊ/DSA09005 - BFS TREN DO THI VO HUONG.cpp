#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};

void BFS(int x){
	queue<int>q;
	q.push(x);
	visited[x] = 1;
	while(q.size()!=0){
		int p = q.front();
		cout<<p<<" ";
		q.pop();
		for(int i: ke[p]){
			if(visited[i]==0){
				q.push(i);
				visited[i]=1;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int dinh, canh, v;
		cin>>dinh>>canh>>v;
		memset(visited,0,sizeof(visited));
		for(int i =1;i<=dinh;i++) ke[i].clear();
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
		}
		BFS(v);
		cout<<endl;
	}
}
