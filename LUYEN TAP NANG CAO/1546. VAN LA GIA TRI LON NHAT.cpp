#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
struct Node {
    int lazy = 0;  
    int val = 0;   
} nodes[MAXN * 4];

void down(int id) {
    int t = nodes[id].lazy;
    if (t != 0) { 
        nodes[id * 2].lazy += t;
        nodes[id * 2].val += t;
        nodes[id * 2 + 1].lazy += t;
        nodes[id * 2 + 1].val += t;
        nodes[id].lazy = 0; 
    }
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u)  return;
    if (u <= l && r <= v) {
        nodes[id].val += val;
        nodes[id].lazy += val;
        return;
    }
    int mid = (l + r) / 2;
    down(id); 
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    nodes[id].val = max(nodes[id * 2].val, nodes[id * 2 + 1].val);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return -1e9; 
    if (u <= l && r <= v) return nodes[id].val;
    int mid = (l + r) / 2;
    down(id); 
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
    int N, Q;
    cin >> N >> Q;;
    while (Q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if(type==1){
            int k; cin>>k;
            update(1, 1, N, u, v, k);
        } else if (type==2) cout << get(1, 1, N, u, v) << endl;
    }
}
