#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
int truoc[1005]={};
vector<int>ans;

void BFS(int x){
	queue<int>q;
	q.push(x);
	visited[x]=1;
	while(q.size()!=0){
		int x = q.front();
		ans.push_back(x);
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
	int dinh, canh, v;
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
	for(int i=1;i<ans.size();i++){
		cout<<truoc[ans[i]]<<"->"<<ans[i]<<endl;
	}
}