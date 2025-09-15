#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int par[MAXN], sze[MAXN];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void Union(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (sze[x] < sze[y]) swap(x, y);
    par[y] = x;
    sze[x] += sze[y];
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i, sze[i] = 1;
    //Nhập các cạnh
    vector<pair<int,int>> e(m+1);
    for (int i = 1; i <= m; i++) cin >> e[i].first >> e[i].second;
    //Nhập tâp cạnh S gồm k cạnh
    int k; cin >> k;
    vector<int> s(k);
    vector<char> inS(m + 1,0);
    for (int i = 0; i < k; i++) { 
        cin >> s[i]; 
        inS[s[i]] = 1; 
    }
    // 1) DSU trên H = (V, E \ S)
    for (int i = 1; i <= m; i++) {
        if (!inS[i]) Union(e[i].first, e[i].second);
    }
    //Coi mọi đỉnh trong cùng 1 TPLT của H như một siêu đỉnh
    // 2) Đồ thị thành phần G' = (V', S) với V' là các TPLT của H
    vector<long long> deg(n+1, 0);
    vector<vector<int>> adj(n+1);
    vector<char> used(n+1, 0);
    for (int id: s) {
        int u = e[id].first, v = e[id].second;
        int cu = find(u), cv = find(v);
        deg[cu]++; deg[cv]++;
        used[cu] = used[cv] = 1;
        if (cu != cv) {
            adj[cu].push_back(cv);
            adj[cv].push_back(cu);
        }
    }
    // 3) Đếm số siêu đỉnh không bị treo (Có bậc khác 0)
    int start = -1, need = 0;
    for (int i = 1; i <= n; i++) {
        if (used[i] && deg[i] > 0) { 
            if (start == -1) start = i; 
            need++; 
        }
    }
    if (need == 0) { 
        cout << "Yes\n"; 
        return 0; 
    }
    // 4) Check xem các siêu đỉnh có cùng TPLT hay không
    vector<char> vis(n + 1,0);
    queue<int> q; q.push(start); vis[start]=1;
    int seen = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v]=1; q.push(v);
                if (used[v] && deg[v] > 0) seen++;
            }
        }
    }
    if (seen != need) { cout << "No\n"; return 0; }
    // 5) Điều kiện Euler trail: số đỉnh bậc lẻ ∈ {0,2}
    int odd = 0;
    for (int i = 1; i <= n; i++) if (used[i] && (deg[i]&1)) odd++;
    cout << ((odd == 0 || odd == 2) ? "Yes\n" : "No\n");
}
