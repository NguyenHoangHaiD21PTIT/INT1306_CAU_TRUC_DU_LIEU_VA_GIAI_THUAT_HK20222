#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100005;
int par[MAX_N];
// weight[x] lưu trữ tổng trọng số từ nút x đến cha của nó
int weight[MAX_N];//tổng chênh lệch trọng lượng từ nút x đến cha của nó trong DSU
int find(int x) {
    if (par[x] != x) {
        int parent = par[x];
        par[x] = find(par[x]);          
        weight[x] += weight[parent];     
    }
    return par[x];
}
void Union(int a, int b, int w) {
    int rootA = find(a);  
    int rootB = find(b);  
    if (rootA == rootB) return; 
    par[rootB] = rootA;
    weight[rootB] = w + weight[a] - weight[b];
}
int main() {
    int T; 
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M; 
        for (int i = 1; i <= N; i++) {
            par[i] = i;       
            weight[i] = 0;   
        }
        while(M--) {
            char q;
            cin >> q;
            if (q == '!') {
                int a, b, w;
                cin >> a >> b >> w;  
                Union(a, b, w);
            } else if (q == '?') {
                int a, b;
                cin >> a >> b;
                if (find(a) != find(b)) cout << "UNKNOWN\n";
                else cout << weight[b] - weight[a] << "\n";
            }
        }
    }
}
