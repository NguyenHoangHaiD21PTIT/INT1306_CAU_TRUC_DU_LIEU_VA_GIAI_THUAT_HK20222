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
		int dinh, canh, v;
		cin>>dinh>>canh>>v;
		for(int i=1;i<=dinh;i++) ke[i].clear();
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
		}
		for(int i = 1;i<=dinh;i++){
			memset(visited,0,sizeof(visited));
			memset(truoc,0,sizeof(truoc));
			if(i==v) continue;
			BFS(v); //v-->i
			int tmp = i;
			if(visited[tmp]==0){
				cout<<"No path"<<endl;
			} else {	
				vector<int>path;
				while(tmp!=v){
					path.push_back(tmp);
					tmp = truoc[tmp];
				}
				path.push_back(v);
				for(int i = path.size()-1;i>=0;i--) cout<<path[i]<<" ";
				cout<<endl;
			}
		}
	}
}
