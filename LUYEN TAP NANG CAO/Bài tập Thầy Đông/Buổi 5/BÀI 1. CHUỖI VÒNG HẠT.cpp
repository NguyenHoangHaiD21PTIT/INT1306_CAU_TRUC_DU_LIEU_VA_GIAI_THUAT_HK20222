#include <bits/stdc++.h>
using namespace std;

int n; 
vector<pair<int,int>> e;
vector<int> b; // mảng nhị phân
int ok;        // còn sinh được không

const int K = 7; // các đỉnh 0..6

void sinh() {
    int i = n - 1;
    while (i >= 0 && b[i] == 1) {
        b[i] = 0;
        i--;
    }
    if (i == -1) ok = 0;
    else b[i] = 1;
}

int main() {
    cin >> n;
    e.resize(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        e[i] = {s.front() - '0', s.back() - '0'};
    }
    int best = 0;
    b.assign(n, 0); ok = 1;
    while (ok) {
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(b[i] == 1) cnt++;
        }
        // Kiểm tra Chu trình Ơ - le
        if (cnt >= 3) {
            int deg[K] = {}, adj[K][K] = {};//adj[u][v]: Số cạnh nối giữa u và v
            for (int i = 0; i < n; i++) {
                if (b[i]) {
                    int u = e[i].first, v = e[i].second;
                    if (u == v) deg[u] += 2;
                    else deg[u]++, deg[v]++, adj[u][v]++, adj[v][u]++;
                }
            }
            bool okDeg = true;//Giả sử các đỉnh đều có bậc chẵn
            //Kiểm tra xem có dính đỉnh bậc lẻ không. Nếu có thì chọn 1 đỉnh để code BFS check liên thông
            int st = -1, need = 0;
            for (int u = 0; u < K; u++) {
                if (deg[u] & 1) { 
                    okDeg = false; 
                    break; 
                }
                if (deg[u] > 0) { 
                    need++; 
                    if (st == -1) st = u; 
                }
            }
            //có need đỉnh bậc chẵn. Check liên thông cho need đỉnh này
            if (okDeg && need > 0) {
                vector<int> vis(K);
                queue<int> q; q.push(st); vis[st] = 1;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v = 0; v < K; v++){
                        if (adj[u][v] && !vis[v]) vis[v] = 1, q.push(v);
                    }
                }
                int seen = 0; 
                for (int u = 0; u < K; u++) if (deg[u] > 0) seen += vis[u];
                if (seen == need) best = max(best, cnt);
            }
        }
        sinh(); 
    }
    cout << best;
}
