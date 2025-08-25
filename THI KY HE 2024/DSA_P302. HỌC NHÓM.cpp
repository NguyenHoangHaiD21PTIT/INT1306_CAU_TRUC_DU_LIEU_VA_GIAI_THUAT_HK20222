#include <bits/stdc++.h>
using namespace std;

vector<int> par(200008);
vector<int> sze(200008, 1);

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
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        par[i] = i;
        sze[i] = 1;
    }
    while (M--){
        int x, y; cin >> x >> y;
        Union (x, y);
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        if(i == find(i)) cnt++;
    }
    cout << cnt;
}
