#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Cấu trúc cạnh: v = đỉnh đích, t = thời gian đi, k = tần suất tàu
struct E { 
    int v; ll t, k; 
};

const ll INF = 1e18;

int main() {
    int n, m, s, f; // n = số thành phố, m = số tuyến, s = start, f = finish
    cin >> n >> m >> s >> f;
    vector<vector<E>> g(n+1); // danh sách kề
    for(int i = 0; i < m; i++){
        int a,b; ll t, k;
        cin >> a >> b >> t >> k;
        g[a].push_back({b, t, k}); 
        g[b].push_back({a, t, k});
    }
    vector<ll> d(n+1, INF); // d[i] = thời gian sớm nhất tới i
    d[s]=0; // thời gian tới start = 0
    // Min-heap Dijkstra: {thời gian, đỉnh}
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [cur, u] = pq.top(); pq.pop(); // lấy đỉnh có thời gian nhỏ nhất
        if(cur > d[u]) continue; // nếu đã cập nhật tốt hơn, bỏ qua
        // Duyệt tất cả các cạnh từ u
        for(auto &e: g[u]){
            // Tính thời điểm tàu tiếp theo ≥ cur
            ll dep; 
            if(cur % e.k == 0) dep = cur;       // vừa đúng mốc tàu, đi ngay
            else dep = (cur / e.k + 1) * e.k;   // chờ tàu tiếp theo
            //Chẳng hạn: Mốc tàu là 3, 6, 9, 12, ..., 3K. Mình đến đúng các mốc thì đi luôn (Đúng mốc là chia hết cho 3)
            //Đến không đúng mốc thì phải chờ mốc tiếp theo, tức là số nguyên nhỏ nhất lớn hơn thời gian đến, là bội của 3 
            //Ví dụ: Mốc 3K, đến lúc 13. Thì phải chờ đến 15
            ll arr = dep + e.t; // thời gian tới đỉnh e.v
            // Relaxation: cập nhật nếu tốt hơn
            if(arr < d[e.v]){
                d[e.v] = arr;
                pq.push({arr,e.v});
            }
        }
    }
    cout << (d[f] == INF ? -1: d[f]);
}
