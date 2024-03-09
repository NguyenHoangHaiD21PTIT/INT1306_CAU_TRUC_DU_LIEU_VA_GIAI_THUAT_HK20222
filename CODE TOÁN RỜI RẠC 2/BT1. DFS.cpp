#include<bits/stdc++.h>
using namespace std;

int a[1005][1005]; //ma tran ke de cho
int n; //so dinh
int visited[1005]; //mang visited danh dau la dinh do da tham

void DFS(int u){
    visited[u] = 1;
    cout<<u<<" ";
    for(int i = 1;i<=n;i++){ 
        if(visited[i]==0&&a[u][i])  DFS(i);
        //Xet cac dinh ke voi u ma chua tham thi DFS vao
    }
} 

int main(){
	cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    int v;
    cin>>v;
    DFS(v);
}