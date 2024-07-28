#include <bits/stdc++.h>
using namespace std;

vector<int> parent, size;
vector<vector<int>> adj;
vector<bool> present;
vector<string> result;

int find(int u) {
    if (u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    parent.resize(N + 1);
    size.resize(N + 1, 1);
    adj.resize(N + 1);
    present.resize(N + 1, false);
    result.resize(N);
    for (int i = 1; i <= N; ++i) parent[i] = i;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];
    int components = 0;
    for (int i = N - 1; i >= 0; --i) {
        int u = P[i];
        present[u] = true;
        components++;
        for (int v : adj[u]) {
            if (present[v]) {
                if (find(u) != find(v)) {
                    unite(u, v);
                    components--;
                }
            }
        }
        result[i] = (components == 1) ? "YES" : "NO";
    }
    for (int i = 0; i < N; ++i) cout << result[i] << "\n";
}
