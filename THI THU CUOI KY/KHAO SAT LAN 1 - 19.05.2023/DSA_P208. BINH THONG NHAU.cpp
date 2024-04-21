#include <iostream>
#include <vector>
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q;
    cin >> Q;
    for (int i = 1; i <= 100001; i++) {
        par[i] = i;
        sze[i] = 1;
    }
    
    for (int q = 0; q < Q; q++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        if (Z == 1) Union(X, Y);
        else {
            if (find(X) == find(Y)) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}