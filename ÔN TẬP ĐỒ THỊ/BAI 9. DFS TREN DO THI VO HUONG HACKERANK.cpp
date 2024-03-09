#include<bits/stdc++.h>
using namespace std;

vector<int>ke[1005];//vector luu cac dinh ke, ke[i] luu cac dinh ke dinh thu i

int visited[1005]={};

void DFS(int x){//DFS tu dinh v
    cout<<x<<" ";
    visited[x]=1;
    for(int i=0;i<ke[x].size();i++){
        if(visited[ke[x][i]]==0){
            DFS(ke[x][i]);
        }
    }
}
int main(){
    int dinh, canh, v;
    cin>>dinh>>canh>>v;//v: dinh bat dau duyet
    while(canh--){
        int dau, cuoi;
        cin>>dau>>cuoi;
        //chuyen sang danh sach ke
        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
    }
    for(int i=1;i<=dinh;i++){
        sort(ke[i].begin(), ke[i].end());
    }
    DFS(v);
}