#include<bits/stdc++.h>
using namespace std;

int visited[10050]={}, truoc[10050]={};
vector<int>ke[100];
vector<int>ans;

void BFS(int x){
	queue<int>q;
	q.push(x);
	visited[x]=1;
	while(q.size()!=0){
		int p = q.front();
		ans.push_back(p);
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
		memset(visited,0,sizeof(visited));
		memset(truoc,0,sizeof(truoc));
		int dinh, canh, v;
		cin>>dinh>>canh>>v;
		ans.clear();
		for(int i=1;i<=dinh;i++){
			ke[i].clear();
		}
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
		}
		BFS(v);
		if(ans.size()<dinh){
			cout<<-1<<endl;
		} else {
			for(int i =1;i<ans.size();i++){
				cout<<truoc[ans[i]]<<" "<<ans[i]<<endl;
			}
		}
	}
}
