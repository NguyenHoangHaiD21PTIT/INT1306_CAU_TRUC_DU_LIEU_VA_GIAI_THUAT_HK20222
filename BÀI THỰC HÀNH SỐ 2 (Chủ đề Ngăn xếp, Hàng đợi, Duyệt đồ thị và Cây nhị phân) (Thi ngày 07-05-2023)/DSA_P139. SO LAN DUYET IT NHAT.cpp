#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> g[N], gr[N];
int vis[N], comp[N];//comp[u] = v: Đỉnh u thuộc TPLT thứ v
stack<int> st;
int scc;

void DFS1(int u) {
    vis[u] = 1;
    for (int v : g[u]){
        if (!vis[v]) DFS1(v);
    }
    st.push(u);
}

void DFS2(int u, int c) {
    comp[u] = c;
    vis[u] = 1;
    for (int v : gr[u]){
        if (!vis[v]) DFS2(v, c);
    }
}

int main() {
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    //B1: Chạy DFS1 để lấy thứ tự topo
    for (int i = 1; i <= n; i++){
        if (!vis[i]) DFS1(i);
    }
    //B2: Xem mỗi đỉnh thuộc Thành phần liên thông mạnh thứ mấy
    memset(vis, 0, sizeof(vis));
    scc = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!vis[u]) DFS2(u, ++scc);
    }
    // B3: Tính số cạnh đi vào từ đỉnh thuộc TPLT mạnh khác vào TPLT mạnh
    vector<int> indeg(scc + 1, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (comp[u] != comp[v]) indeg[comp[v]]++;
        }
    }
    // B4: Đếm số Thành phần liên thông không có cạnh vào
    int ans = 0;
    for (int c = 1; c <= scc; c++) {
        if (indeg[c] == 0) ans++;
    }
    cout << ans;
}
/*TPLT có cạnh đi vào:
Nếu DFS trong này thì chỉ đi được đến các SCC mà nó có đường đi tới. Nhưng nếu đi từ các SCC có số cạnh vào là 0 thì nó vừa 
quét cả SCC này, vừa quét cả SCC mà nó đi tới luôn
Nếu không bắt đầu DFS từ các TPLT có bậc vào = 0, các đỉnh trong SCC này sẽ không bao giờ được DFS tới, vì không có đường đi từ SCC khác.
*/
