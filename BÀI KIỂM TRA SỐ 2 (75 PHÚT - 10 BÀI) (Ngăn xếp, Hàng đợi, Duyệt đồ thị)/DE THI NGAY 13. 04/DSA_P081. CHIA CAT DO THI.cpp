#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};

void DFS(int x){
	visited[x]=1;
	for(int i: ke[x]){
		if(visited[i]==0) DFS(i);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(visited, 0, sizeof(visited));
		int dinh, canh;
		cin>>dinh>>canh;
		for(int i=1;i<=dinh;i++) ke[i].clear();
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			ke[dau].push_back(cuoi);
			ke[cuoi].push_back(dau);
		}
		int cntgoc=0;
		for(int i=1;i<=dinh;i++){
			if(visited[i]==0){
				DFS(i);
				cntgoc++;
			}
		}
		int res = 0, ans = -1;
		for(int i=1;i<=dinh;i++){
			memset(visited,0,sizeof(visited));
			visited[i] = 1;//Khong cho DFS vao i
			int cnt  = 0;
			for(int j=1;j<=dinh;j++){
				if(visited[j]==0){
					cnt++;
					DFS(j);
				}
			}
			if(cnt>cntgoc&&cnt>res) {
				res = cnt;
				ans = i;
			}
		}
		if(ans == -1) cout<<0<<endl;
		else cout<<ans<<endl;
	}
}
		
