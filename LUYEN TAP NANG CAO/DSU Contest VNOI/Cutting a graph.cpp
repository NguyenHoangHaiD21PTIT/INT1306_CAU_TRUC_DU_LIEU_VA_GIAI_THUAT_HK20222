#include<bits/stdc++.h>
using namespace std;

int par[100005], sze[100005];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sze[x] < sze[y]) swap(x, y); 
    par[y] = x; 
    sze[x] += sze[y]; 
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sze[i] = 1;
    }
    vector<pair<int, int>> edge(m + 1);
    for (int i = 1; i <= m; i++) cin >> edge[i].first >> edge[i].second;
    vector<pair<string, pair<int, int>>> que(q);
    set<pair<int, int>>deleted;
    for (int i = 0; i < q; i++) {
        string type;
        int x, y;
        cin >> type >> x >> y;
        que[i] = {type, {x, y}};
        if (type == "cut") deleted.insert({min(x, y), max(x, y)});
    }
    for (int i = 1; i <= m; i++) {
        int u = edge[i].first, v = edge[i].second;
        if (deleted.find({min(u, v), max(u, v)}) == deleted.end()) Union(u, v);
    }
    vector<string> res;
    for (int i = q - 1; i >= 0; i--) {
        string type = que[i].first;
        int x = que[i].second.first, y = que[i].second.second;
        if (type == "ask") {
            if (find(x) == find(y)) res.push_back("YES");
            else res.push_back("NO");
        } else if (type == "cut") Union(x, y);
    }
    reverse(res.begin(), res.end());
    for (const string &res : res) cout << res << '\n';
}
