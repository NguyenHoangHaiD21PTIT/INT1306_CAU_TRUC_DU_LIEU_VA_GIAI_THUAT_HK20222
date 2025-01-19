#include <bits/stdc++.h>
using namespace std;

vector<int> par(300008), sze(300008, 1), maxElem(300008), minElem(300008);

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
    maxElem[x] = max(maxElem[x], maxElem[y]);
    minElem[x] = min(minElem[x], minElem[y]);
    return true;
}

int main() {
    int n, Q;
    cin >> n >> Q;
    for (int i = 1; i <= 300001; i++) {
        par[i] = i;
        sze[i] = 1;
        maxElem[i] = i;
        minElem[i] = i;
    }
    for (int q = 0; q < Q; q++) {
        string Z;int X, Y; 
        cin >> Z >> X;
        if (Z == "union"){
            cin>>Y;
            Union(X, Y);
        } else {
            int root = find(X);
            cout << minElem[root]<<" "<<maxElem[root] << " " << sze[root] << '\n';
        }
    }
}