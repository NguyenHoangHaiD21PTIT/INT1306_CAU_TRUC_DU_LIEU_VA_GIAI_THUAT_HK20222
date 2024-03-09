#include<bits/stdc++.h>
using namespace std;

int a[1005][1005]; //ma tran ke de cho
int n, visited[1005]; //so dinh, mang visited danh dau la dinh do da tham

void DFS(int u){
    visited[u] = 1;
    for(int i = 1;i<=n;i++){ 
        if(visited[i]==0&&a[u][i])  DFS(i);
        //Xet cac dinh ke voi u ma chua tham thi DFS vao
    }
} 

int TPLT_DFS(int a[][1005]){
	int res = 0;
	for(int i = 1;i<=n;i++){
		if(visited[i]==0){
			res++;
			DFS(i);
		}
	}
	return res;
}
int main(){
	cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    cout<<TPLT_DFS(a);
}