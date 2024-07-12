#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1005];
int visited[1005];

void DFS(int x){
    visited[x] = 1;
    for(int i: adj[x]){
        if(!visited[i]) DFS(i);
    }
}

int main(){
    int v, e;
    cin>>v>>e;
    while(e--){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1);
    int check = 0;
    for(int i = 2;i<=v;i++){
        if(!visited[i]){
            check = 1;
            cout<<i<<endl;
        }
    }
    if(!check) cout<<0;
}