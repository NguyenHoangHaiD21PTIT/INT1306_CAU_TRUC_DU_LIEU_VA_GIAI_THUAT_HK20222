#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18; 
const int MAXN = 100005; 

vector<pair<int, ll>> adj[MAXN];
ll dist[MAXN]; 
ll cnt[MAXN]; // Đổi tên count thành cnt để tránh xung đột với std::count

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }
    for (int i = 1; i <= n; i++) dist[i] = INF; // Khởi tạo khoảng cách và số đường đi
    // Hàng đợi ưu tiên (Min-Heap) lưu {khoảng cách, đỉnh}
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    // Bắt đầu từ đỉnh 1
    dist[1] = 0;
    cnt[1] = 1;
    pq.push({0, 1});
    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto e: adj[u]) {
            int v = e.first;
            ll w = e.second;
            // Trường hợp 1: Tìm thấy đường đi ngắn hơn
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u]; // Gán lại số đường đi
                pq.push({dist[v], v});
            } else if (dist[u] + w == dist[v]) cnt[v] += cnt[u]; // Cộng dồn số cách đi
            // Trường hợp 2: Tìm thấy thêm đường đi có độ dài BẰNG đường đi ngắn nhất
        }
    }
    cout << dist[n] << " " << cnt[n];
}
