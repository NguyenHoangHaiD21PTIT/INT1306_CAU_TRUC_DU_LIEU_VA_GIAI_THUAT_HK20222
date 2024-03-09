#include<bits/stdc++.h>
using namespace std;

int dem;//dem so TPLT
vector<int> ke[1005];
int visited[1005]={};
vector<int>lt[1005];//lt[i] la vector luu cac dinh trong tplt thu i

bool cmp(int a, int b){
    if(ke[a].size()!=ke[b].size()) return ke[a].size()>ke[b].size();
    return a<b;
}

void DFS(int u){
    visited[u]=1;
    lt[dem].push_back(u);
    for(int i: ke[u]){
        if(visited[i]==0) DFS(i);
    }
}
    
int main(){
    int dinh, canh;
    cin>>dinh>>canh;
    while(canh--){
        int dau, cuoi;
        cin>>dau>>cuoi;
        ke[dau].push_back(cuoi);
        ke[cuoi].push_back(dau);
    }
    
    //1. Dem so TPLT va gan
    for(int i=1;i<=dinh;i++){
        if(visited[i]==0){
            dem++;
            DFS(i);
        }
    }
    
    //2. Sap xep de tim ra "nhom truong"
    for(int i=1;i<=dem;i++) sort(lt[i].begin(),lt[i].end(),cmp);
    vector<int>v;
    for(int i=1;i<=dem;i++) v.push_back(lt[i][0]);
    sort(v.begin(),v.end());
    for(int i: v) cout<<i<<" ";
}

	