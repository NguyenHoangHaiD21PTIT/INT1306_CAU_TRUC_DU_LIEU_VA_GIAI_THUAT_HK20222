#include <bits/stdc++.h>

using namespace std;

using ll = long long;
vector<pair<int, int>>adj[100005];
int route[100005];
int n, m, s;
int d[100005];
void Dijsktra(int s) {
    fill(d + 1, d + n + 1, 1e9);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({d[s], s});
    route[1] = 1;
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du > d[u]) continue;
        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (d[v] < d[u] + w) continue;
            if (d[v] == d[u] + w) {
                route[v] += route[u];
            }
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                route[v] = route[u];
                pq.push({d[v], v});
            }
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    Dijsktra(1);
    cout << d[n] << " " << route[n];
    return 0;
}