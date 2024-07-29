#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
vector<long long> dijkstra(long long start, vector<vector<pair<long long, long long>>>& graph, long long N) {
    vector<long long> dist(N + 1, INF);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        long long d = pq.top().first;
        long long u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : graph[u]) {
            long long v = edge.first;
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
    long long T;
    cin >> T;
    while (T--) {
        long long N, M;
        cin >> N >> M;
        long long H1, S1, H2, S2;
        cin >> H1 >> S1 >> H2 >> S2;
        vector<vector<pair<long long, long long>>> graph(N + 1);
        for (long long i = 0; i < M; ++i) {
            long long u, v;
            long long c;
            cin >> u >> v >> c;
            graph[u].push_back({v, c});
            graph[v].push_back({u, c});
        }
        auto dist_H1 = dijkstra(H1, graph, N);
        auto dist_S1 = dijkstra(S1, graph, N);
        auto dist_H2 = dijkstra(H2, graph, N);
        auto dist_S2 = dijkstra(S2, graph, N);

        long long d_H1_S1 = dist_H1[S1];
        long long d_H2_S2 = dist_H2[S2];

        // Kiểm tra trường hợp gặp nhau vô hạn
        bool infinite = (d_H1_S1 == dist_H1[H2] + dist_H2[S1] && dist_H1[H2] + dist_H2[S1] == dist_H1[S2]) || 
                        (d_H2_S2 == dist_H2[H1] + dist_H1[S2] && dist_H2[H1] + dist_H1[S2] == dist_H2[S1]);

        if (infinite) {
            cout << "infinity\n";
        } else {
            long long count = 0;
            for (long long i = 1; i <= N; ++i) {
                if (dist_H1[i] + dist_S1[i] == d_H1_S1 && dist_H2[i] + dist_S2[i] == d_H2_S2) ++count;
            }
            cout << count << "\n";
        }
    }
}




