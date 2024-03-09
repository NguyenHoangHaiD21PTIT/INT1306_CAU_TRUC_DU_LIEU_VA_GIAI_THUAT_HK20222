#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];
int visited[1005]={};
int tplt[1005]={};//tplt[x]=y: y thuoc thanh phan lien thong thu x
int cnt = 0;//so thanh phan lien thong

void DFS(int x){
	visited[x] =1;
	tplt[x]=cnt;
	for(int i: ke[x]){
		if(visited[i]==0){
			DFS(i);
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
		for(int i=1;i<=dinh;i++){
			if(visited[i]==0){
				DFS(i);
				cnt++;
			}
		}
		int q;
		cin>>q;
		while(q--){
			int x, y;
			cin>>x>>y;
			if(tplt[x]==tplt[y]){
				cout<<"YES"<<endl;
			} else {
				cout<<"NO"<<endl;
			}
		}
	}	
}
		