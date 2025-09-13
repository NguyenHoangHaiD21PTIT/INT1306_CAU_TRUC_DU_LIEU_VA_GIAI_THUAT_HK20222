#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);   
    vector<int> deg(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        u--; v--;
        if (c == 1) {          
            adj[u].push_back(v);
            adj[v].push_back(u);
            ++deg[u]; ++deg[v];
        }
    }
    vector<int> vis(n, 0);
    long long ans = 0;
    //Xét từng TPLT
    for (int s = 0; s < n; ++s) {
        //Bỏ qua các đỉnh đã thăm và các đỉnh treo
        if (vis[s]) continue;
        if (adj[s].empty()) {    
            vis[s] = 1;
            continue;
        }
        queue<int> q; q.push(s); vis[s] = 1;
        long long e_cnt = 0;   
        int odd_deg = 0;//Số đỉnh bậc lẻ
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (deg[u] & 1) odd_deg++;
            e_cnt += (int)adj[u].size();
            for (int v : adj[u]){
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        e_cnt /= 2; //Vì tính cả chiều đi lẫn chiều về nên bị tính 2 lần -> Chia đôi
        if (e_cnt > 0) {
            //Không có đinh bậc lẻ nào -> TPLT tạo thành chu trình
            if (odd_deg == 0) ans += 1;     
            //Có đỉnh bậc lẻ. Mỗi lần phải chọn 2 đỉnh bậc lẻ để làm điểm xuất phát và kết thúc
            else ans += odd_deg / 2;        
        }
    }
    cout << ans;
}
