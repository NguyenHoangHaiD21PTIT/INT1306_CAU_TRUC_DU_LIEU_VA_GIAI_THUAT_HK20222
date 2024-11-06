#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;  
vector<int> st[4 * MAXN]; 
int a[MAXN];              

void build(int id, int l, int r) {
    if (l == r) {
        st[id].push_back(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);      
    build(id * 2 + 1, mid + 1, r); 
    merge(st[id * 2].begin(), st[id * 2].end(), st[id * 2 + 1].begin(), st[id * 2 + 1].end(), back_inserter(st[id]));
}

int get(int id, int l, int r, int u, int v, int k) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id].size() - (upper_bound(st[id].begin(), st[id].end(), k) - st[id].begin());
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v, k) + get(id * 2 + 1, mid + 1, r, u, v, k);
}

int main() {
    int N, Q;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    build(1, 0, N - 1);
    cin >> Q;
    while (Q--) {
        int u, v, k;
        cin >> u >> v >> k;
        u--; v--;
        cout << get(1, 0, N - 1, u, v, k) << endl;
    }
}
