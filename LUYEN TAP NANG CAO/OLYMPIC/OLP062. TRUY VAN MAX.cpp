#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
long long t[4 * MAXN], lazy[4 * MAXN], A[MAXN];
long long N, M;               

void build(long long v, long long l, long long r) {
    if (l == r) {
        t[v] = A[l]; 
    } else {
        long long m = (l + r) / 2;
        build(2 * v, l, m);            
        build(2 * v + 1, m + 1, r);   
        t[v] = max(t[2 * v], t[2 * v + 1]); 
    }
}

void propagate(long long v, long long l, long long r) {
    if (lazy[v] != 0) {
        t[v] += lazy[v]; 
        if (l != r) {    
            lazy[2 * v] += lazy[v];       
            lazy[2 * v + 1] += lazy[v];   
        }
        lazy[v] = 0; 
    }
}

void update(long long v, long long l, long long r, long long u, long long v_end, long long x) {
    propagate(v, l, r); 
    if (v_end < l || u > r) return; 
    if (u <= l && r <= v_end) { 
        lazy[v] += x;
        propagate(v, l, r);
    } else { 
        long long m = (l + r) / 2;
        update(2 * v, l, m, u, v_end, x);
        update(2 * v + 1, m + 1, r, u, v_end, x);
        t[v] = max(t[2 * v], t[2 * v + 1]); 
    }
}

long long query(long long v, long long l, long long r, long long u, long long v_end) {
    propagate(v, l, r); 
    if (v_end < l || u > r) return LLONG_MIN;
    if (u <= l && r <= v_end) return t[v]; 
    long long m = (l + r) / 2;
    return max(query(2 * v, l, m, u, v_end), query(2 * v + 1, m + 1, r, u, v_end));
}

int main() {
    cin >> N >> M;
    for (long long i = 1; i <= N; i++) cin >> A[i];
    build(1, 1, N);
    for (long long i = 0; i < M; i++) {
        long long type, u, v;
        long long x;
        cin >> type >> u >> v;
        if (type == 1) cout << query(1, 1, N, u, v) << "\n";
        else if (type == 2) {
            cin >> x;
            update(1, 1, N, u, v, x);
        }
    }
}
