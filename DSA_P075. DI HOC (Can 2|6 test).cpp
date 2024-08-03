#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Thực hiện thuật toán Dijkstra từ đỉnh x tới mọi đỉnh
vector<long long> Dijkstra(long long start, vector<vector<pair<long long, long long>>>& graph, long long N) {
    vector<long long> dist(N + 1, INF);
    dist[start] = 0;
    
    // pq: Lưu {d[v], v}
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        // Mỗi bước, lấy ra đỉnh chưa xét mà có d min, gọi là đỉnh u
        pair<long long, long long> p = pq.top();
        long long d = p.first, u = p.second;
        pq.pop();

        // Xét các đỉnh kề với u
        for (auto edge : graph[u]) {
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
        
        // Thực hiện thuật toán Dijkstra từ 4 đỉnh H1, S1, H2, S2
        auto dist_H1 = Dijkstra(H1, graph, N);
        auto dist_S1 = Dijkstra(S1, graph, N);
        auto dist_H2 = Dijkstra(H2, graph, N);
        auto dist_S2 = Dijkstra(S2, graph, N);

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



