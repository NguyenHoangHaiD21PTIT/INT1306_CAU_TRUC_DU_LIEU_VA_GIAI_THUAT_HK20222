#include<bits/stdc++.h>
using namespace std;

int a[1005][1005], d[1005][1005], visited[1005][1005];
//d[i][j] la so buoc toi thieu de di chuyen tu o dau den o cuoi ma tran

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++) cin>>a[i][j];
		}
		memset(d, 0, sizeof(d));
		memset(visited, 0, sizeof(visited));
		//Tien hanh BFS tu o (0,0)
		queue<pair<int,int>>q;
		q.push({0,0});
		visited[0][0] = 1;
		d[0][0] = 0;
		//Loang tu dau hang doi
		int check = 0;
		while(!q.empty()){
			pair<int,int>p = q.front(); q.pop();
			int i = p.first, j = p.second;
			if(i==n-1&&j==m-1){
				check = 1;
				cout<<d[i][j]<<endl;
				break;
			}
			int i1 = i + a[i][j], j1 = j +  a[i][j];
			if(i1<n&&!visited[i1][j]){
				q.push({i1,j});
				visited[i1][j] = 1;
				d[i1][j] = d[i][j] + 1;
			}
			if(j1<m&&!visited[i][j1]){
				q.push({i, j1});
				visited[i][j1] = 1;
				d[i][j1] = d[i][j] + 1;
			}	
		}
		if(!check) cout<<-1<<endl;
	}
}