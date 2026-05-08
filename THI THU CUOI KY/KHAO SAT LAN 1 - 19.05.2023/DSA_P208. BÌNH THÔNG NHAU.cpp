#include <bits/stdc++.h>
using namespace std;

int p[100005], s[100005];

int find(int x){
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void join(int x, int y){
    x = find(x); y = find(y);
    if (x == y) return;
    if (s[x] < s[y]) swap(x, y);
    p[y] = x; s[x] += s[y];
    return;
}

int main(){
    int q; cin >> q;
    for (int i = 1; i <= 100001; i++) p[i] = i, s[i] = 1;
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
