#include<bits/stdc++.h>
using namespace std;
vector<int>ke[1005];
int visited[1005] = {};

void DFS(int x){
    visited[x] = 1;
    for(int i: ke[x]){
        if(!visited[i]) DFS(i);
    }
}
int main(){
    int dinh, canh;
    cin>>dinh>>canh;
    while(canh--){
        int x, y;
        cin>>x>>y;
        ke[x].push_back(y);
    }
    int ans = INT_MAX;
    for(int i = 1;i<=dinh;i++){
        int cnt = 1;
        memset(visited, 0, sizeof(visited));
        DFS(i);
        for(int k = 1;k<=dinh;k++){
            if(!visited[k]){
                DFS(k);
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    cout<<ans;
}
