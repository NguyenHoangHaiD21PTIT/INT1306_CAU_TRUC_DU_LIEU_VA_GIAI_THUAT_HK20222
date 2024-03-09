#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};

void BFS(int x){
	queue<int>q;
	q.push(x);
	visited[x]=1;
	while(q.size()!=0){
		int p = q.front();
		q.pop();
		for(int i: ke[p]){
			if(visited[i]==0){
				visited[i]=1;
				q.push(i);
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(visited,0,sizeof(visited));
		int dinh, canh;
		cin>>dinh>>canh;
		for(int i=1;i<=dinh;i++){
		    ke[i].clear();
		}
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
		}
		for(int i=1;i<=dinh;i++){
			sort(ke[i].begin(),ke[i].end());
		}
		int ans = 0;
		for(int i=1;i<=dinh;i++){
			if(visited[i]==0){
				ans++;
				BFS(i);
			}
		}
		cout<<ans<<endl;
	}
}