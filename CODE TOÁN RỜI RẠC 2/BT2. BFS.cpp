#include<bits/stdc++.h>
using namespace std;

int a[1005][1005]; //ma tran ke de cho
int n, visited[1005]; //so dinh, mang visited danh dau la dinh do da tham

void BFS(int u){
    queue<int>q;
    q.push(u);
    visited[u] = 1;
    while(q.size()!=0){
        int p = q.front();
        cout<<p<<" ";
        q.pop();
        for(int i = 1;i<=n;i++){ 
        	if(visited[i]==0&&a[p][i]){ //Xet cac dinh ke voi dinh p ma chua xet
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    int v;
    cin>>v;
    BFS(v);
}