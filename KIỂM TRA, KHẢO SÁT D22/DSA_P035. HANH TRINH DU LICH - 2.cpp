#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18; 
const int MAXK = 15;

vector<long long> Dijkstra(int start, vector<vector<pair<int, long long>>>& graph, int N) {
    vector<long long> dist(N + 1, INF); 
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        long long d = top.first;
        int u = top.second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto edge : graph[u]) {
            int v = edge.first;
            long long w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> Points(K);
    for (int i = 0; i < K; ++i) cin >> Points[i];
    Points.insert(Points.begin(), 1); 
    vector<vector<pair<int, long long>>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
    }

    vector<vector<long long>> dist(K + 1, vector<long long>(N + 1, INF));
    for (int i = 0; i <= K; i++) dist[i] = Dijkstra(Points[i], graph, N);

    vector<vector<long long>> cost(K + 1, vector<long long>(K + 1, INF));
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= K; j++) {
            if (dist[i][Points[j]] < INF) cost[i][j] = dist[i][Points[j]];
        }
    }
    vector<vector<long long>> dp(1 << (K + 1), vector<long long>(K + 1, INF));
    dp[1][0] = 0; 
    for (int mask = 1; mask < (1 << (K + 1)); mask++) {
        for (int i = 0; i <= K; i++) {
            if (!(mask & (1 << i))) continue; 
            for (int j = 0; j <= K; j++) {
                if (i != j && (mask & (1 << j))) dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + cost[j][i]);
            }
        }
    }
    long long res = INF;
    for (int i = 1; i <= K; i++) {
        if (cost[i][0] < INF) res = min(res, dp[(1 << (K + 1)) - 1][i] + cost[i][0]);
    }
    if (res >= INF) cout << -1 << endl;
    else cout << res << endl;
}

