#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int t[4 * MAXN], lazy[4 * MAXN], A[MAXN], N, M;               

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = A[l]; 
    } else {
        int m = (l + r) / 2;
        build(2 * v, l, m);            
        build(2 * v + 1, m + 1, r);   
        t[v] = max(t[2 * v], t[2 * v + 1]); 
    }
}

void propagate(int v, int l, int r) {
    if (lazy[v] != 0) {
        t[v] += lazy[v]; 
        if (l != r) {    
            lazy[2 * v] += lazy[v];       
            lazy[2 * v + 1] += lazy[v];   
        }
        lazy[v] = 0; 
    }
}


void update(int v, int l, int r, int u, int v_end, int x) {
    propagate(v, l, r); 
    if (v_end < l || u > r) return; 
    if (u <= l && r <= v_end) { 
        lazy[v] += x;
        propagate(v, l, r);
    } else { 
        int m = (l + r) / 2;
        update(2 * v, l, m, u, v_end, x);
        update(2 * v + 1, m + 1, r, u, v_end, x);
        t[v] = max(t[2 * v], t[2 * v + 1]); 
    }
}


int query(int v, int l, int r, int u, int v_end) {
    propagate(v, l, r); 
    if (v_end < l || u > r) return INT_MIN;
    if (u <= l && r <= v_end) return t[v]; 
    int m = (l + r) / 2;
    return max(query(2 * v, l, m, u, v_end), query(2 * v + 1, m + 1, r, u, v_end));
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> A[i];
    build(1, 1, N);
    for (int i = 0; i < M; i++) {
        int type, u, v, x;
        cin >> type >> u >> v;
        if (type == 1) cout << query(1, 1, N, u, v) << "\n";
        else if (type == 2) {
            cin >> x;
            update(1, 1, N, u, v, x);
        }
    }
}
