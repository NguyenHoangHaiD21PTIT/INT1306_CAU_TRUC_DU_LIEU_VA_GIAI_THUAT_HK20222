#include <bits/stdc++.h>
using namespace std;

vector<int> par(100008);
vector<int> sze(100008, 1);

int find(int x) {
    if (x == par[x]) return x;
    par[x] = find(par[x]);
    return par[x];
}

bool Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sze[x] < sze[y]) swap(x, y);
    par[y] = x;
    sze[x] += sze[y];
    return true;
}

int main() {
    int n, Q;
    cin >> n >> Q;
    for (int i = 1; i <= 100001; i++) {
        par[i] = i;
        sze[i] = 1;
    }
    for (int q = 0; q < Q; q++) {
        string Z;int X, Y; 
        cin >> Z >> X >> Y;
        if (Z == "union") Union(X, Y);
        else {
            if (find(X) == find(Y)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}