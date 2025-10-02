#include <bits/stdc++.h>
using namespace std;

vector<int> par, sze;

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sze[x] < sze[y]) swap(x, y);
    par[y] = x;
    sze[x] += sze[y];
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> P(n);
    for (int i = 0; i < n; i++) cin >> P[i];
    par.resize(n);
    sze.resize(n, 1);
    for (int i = 0; i < n; i++) par[i] = i;
    for (int i = 0; i < n; i++) Union(i, P[i]);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (find(i) == i) cnt++;
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y)) cout << cnt + 1 << "\n";
        else cout << cnt - 1 << "\n";
    }
}
