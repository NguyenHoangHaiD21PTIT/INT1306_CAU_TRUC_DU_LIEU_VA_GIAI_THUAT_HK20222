#include <bits/stdc++.h>
using namespace std;

int par[100005], s[100005];

int find(int x){
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool join(int x, int y){
    x = find(x); y = find(y);
    if (x == y) return false;
    if (s[x] < s[y]) swap(x, y);
    par[y] = x;
    s[x] += s[y];
    return true;
}

int main(){
    int q; cin >> q;
    for (int i = 1; i <= 100001; i++){
        par[i] = i;
        s[i] = 1;
    }
    while (q--){
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 1) join(x, y);
        else {
            if (find(x) == find(y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}
