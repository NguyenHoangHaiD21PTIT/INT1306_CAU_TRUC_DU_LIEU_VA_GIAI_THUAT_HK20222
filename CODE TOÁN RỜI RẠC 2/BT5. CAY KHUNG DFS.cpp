#include<bits/stdc++.h>
using namespace std;

int a[1005][1005]; //ma tran ke de cho
int n, visited[1005]; //so dinh, mang visited danh dau la dinh do da tham
int par[1005];//par[i] la dinh loang ra i

void DFS(int u){
    visited[u] = 1;
    for(int i = 1;i<=n;i++){ 
        if(visited[i]==0&&a[u][i]){
        //Xet cac dinh ke voi u ma chua tham thi DFS vao
        	DFS(i);
        	par[i] = u;
        }
    }
} 

void T_DFS(int a[][1005], int v){
	DFS(v);//Xay dung cay khung tu dinh v
	//Dem so dinh duoc tham
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(visited[i]) cnt++;
	}
	if(cnt==n){
		cout<<"DFS tree"<<endl;
		for(int i = 1;i<=n;i++){
			if(par[i]) cout<<par[i]<<" "<<i<<endl;
		}
	} else {
		cout<<"Do thi khong lien thong";
	}
}

int main(){
	cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    int v;
    cin>>v;
    T_DFS(a, v);
}