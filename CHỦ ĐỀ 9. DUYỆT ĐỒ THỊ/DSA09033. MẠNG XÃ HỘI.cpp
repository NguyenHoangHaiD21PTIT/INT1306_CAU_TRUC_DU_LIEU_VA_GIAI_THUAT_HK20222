#include <bits/stdc++.h>
using namespace std;
vector<int> par(100008), sze(100008, 1);

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool Union(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (sze[x] < sze[y]) swap(x, y);
    par[y] = x;
    sze[x] += sze[y];
    return true;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        for(int i = 1;i <= N; i++){
            par[i] = i;
            sze[i] = 1;
        }
        for (int i = 0; i < M; i++) {
            int u, v; cin >> u >> v;
            Union(u, v);
        }
        long cnt = 0;
        for (int i = 1; i <= N; i++) {
            if(i == find(i)) cnt += (sze[i]) * (sze[i] - 1) / 2;
        }
        if (cnt == M) cout << "YES\n";
        else cout << "NO\n";
    }
}
