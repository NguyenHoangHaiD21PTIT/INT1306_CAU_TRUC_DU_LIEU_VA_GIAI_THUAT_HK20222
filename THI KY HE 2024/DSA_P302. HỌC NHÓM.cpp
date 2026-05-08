#include <bits/stdc++.h>
using namespace std;

int p[200008], s[200008];

int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void Union(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (s[x] < s[y]) swap(x, y);
    p[y] = x; s[x] += s[y];
    return;
}

int main() {
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {p[i] = i; s[i] = 1;}
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
