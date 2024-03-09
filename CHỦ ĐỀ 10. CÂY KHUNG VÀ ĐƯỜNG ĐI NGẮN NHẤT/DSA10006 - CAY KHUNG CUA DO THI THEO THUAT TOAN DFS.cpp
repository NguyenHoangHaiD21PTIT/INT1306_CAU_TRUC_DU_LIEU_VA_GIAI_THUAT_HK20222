#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
int truoc[1005]={};
vector<int>ans;

void DFS(int x){
	visited[x]=1;
	ans.push_back(x);
	for(int i: ke[x]){
		if(visited[i]==0){
			DFS(i);
			truoc[i] = x;
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
		DFS(v);
		if(ans.size()<dinh){
			cout<<-1<<endl;
		} else {
			for(int i =1;i<ans.size();i++){
				cout<<truoc[ans[i]]<<" "<<ans[i]<<endl;
			}
		}
	}
}