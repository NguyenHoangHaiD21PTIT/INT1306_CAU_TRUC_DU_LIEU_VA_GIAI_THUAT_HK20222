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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    par.resize(n + 1);
    for (int i = 1; i <= n; i++) par[i] = i; 
    vector<int> res;
    for (int i = 0; i < n; i++) {
        int pos = find(p[i]); 
        res.push_back(pos);
        unite(pos, pos % n + 1); 
    }
    for (int x : res) cout << x << " ";
}
