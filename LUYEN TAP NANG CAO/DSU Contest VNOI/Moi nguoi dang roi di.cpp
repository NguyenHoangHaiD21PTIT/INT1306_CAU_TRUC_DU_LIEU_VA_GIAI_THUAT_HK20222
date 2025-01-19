#include <bits/stdc++.h>
using namespace std;

vector<int> par;

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]); 
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) par[x] = y; 
}

int main() {
    int n, q;
    cin >> n >> q;
    par.resize(n + 2);
    for (int i = 1; i <= n + 1; i++) par[i] = i;
    while (q--) {
        char op; int x;
        cin >> op >> x;
        if (op == '-') {
            unite(x, x + 1);
        } else if (op == '?') {
            int res = find(x);
            if (res > n) cout << -1 << "\n"; 
            else cout << res << "\n"; 
        }
    }
}
