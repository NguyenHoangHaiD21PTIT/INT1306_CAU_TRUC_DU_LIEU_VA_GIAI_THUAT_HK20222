#include<bits/stdc++.h>
using namespace std;
int d[100005];
vector <int> adj[100005];//adjacent: đỉnh kề
void DFS(int u, int p=-1){//u và parent của u
    for (int v:adj[u]){
        if (p!=v){
            d[v] = d[u] + 1;
            DFS(v, u);
        }
    }
}
int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //Bước 1: Chọn 1 đỉnh bất kỳ làm gốc. DFS để tìm đỉnh xa nó nhất
    DFS(1);
    //d[i] lưu độ dài đường đi khi DFS từ 1 đến nó
    int root = max_element(d+1, d+n+1) - d;
    //Tìm đỉnh xa 1 nhất --> 1 đầu mút của đường kính
    memset(d, 0, sizeof d);
    //Bước 2: Coi đỉnh tìm được ở Bước 1 là gốc cây. Làm tương tự bước 1 để tìm ra đỉnh xa gốc hiện tại nhất
    DFS(root);
    cout << *max_element(d+1, d+n+1);
}
//https://luyencode.net/problem/ltc_1d
