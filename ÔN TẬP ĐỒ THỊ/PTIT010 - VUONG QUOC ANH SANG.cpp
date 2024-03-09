#include<bits/stdc++.h>
using namespace std;

int visited[1005]={};
vector<int>ke[1005];
vector<pair<int,int>>v;
int a[1005][1005];

void DFS(int x){
	visited[x]=1;
	for(int i: ke[x]){
		if(visited[i]==0){
			DFS(i);
		}
	}
}

void DFS2(int u, int x, int y){
	visited[u]=1;
	for(int i: ke[u]){
		if((u==x&&i==y)||(u==y&&i==x)){
			continue;
		}
		if(visited[i]==0){
			DFS2(i,x,y);
		}
	}
}
int main(){
	int dinh;
	cin>>dinh;
	for(int i=0;i<dinh;i++){
		for(int j=0;j<dinh;j++){
			cin>>a[i][j];
			if(i<j&&a[i][j]==1){
				ke[i+1].push_back(j+1);
				ke[j+1].push_back(i+1);
				v.push_back({i+1,j+1});
			}
		}
	}
/*	for(int i=1;i<=dinh;i++){
		sort(ke[i].begin(), ke[i].end());
	}
	for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl;
    for(int i=1;i<=dinh;i++){
        cout<<i<<" : ";
        for(int j=0;j<ke[i].size();j++){
            cout<<ke[i][j]<<" ";
        }
        cout<<endl;
    } */
	memset(visited,0,sizeof(visited));
	int cntgoc=0;//so tplt goc
	for(int i = 1;i<=dinh;i++){
		if(visited[i]==0){
			cntgoc++;
			DFS(i);
		}
	}
	int ans=0;
	for(auto i: v){
		memset(visited,0,sizeof(visited));
		int x = i.first;
		int y = i. second;
		int cntsau=0;
		for(int j=1;j<=dinh;j++){
			if(visited[j]==0){
				cntsau++;
				DFS2(j,x,y);
			}
		}
		if(cntsau>cntgoc){
			ans++;
		}
	}
	cout<<ans;
}