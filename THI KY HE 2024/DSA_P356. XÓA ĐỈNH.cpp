#include <bits/stdc++.h>
using namespace std;

int p[200005], s[200005];//p: par, s: size
vector<int> g[200005];
string ans[200005];

int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (s[x] < s[y]) swap(x, y);
    p[y] = x;
    s[x] += s[y];
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        s[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> P(n);
    for (int i = 0; i < n; ++i) cin >> P[i];
    int c = 0; // số thành phần liên thông
    vector<bool> on(n + 1, false); 
    // Thêm dần từng đỉnh từ cuối về
    for (int i = n - 1; i >= 0; --i) {
        int u = P[i];
        on[u] = true; // đã thêm vào
        c++;
        for (int v: g[u]) {
            if (on[v] && find(u) != find(v)) {
                join(u, v); 
                c--;
            }
        }
        if (c == 1) ans[i] = "YES";
        else ans[i] = "NO";
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << "\n";
}
/*Tư duy: Thêm ngược từ cuối thêm về
Bỏ từng đỉnh x vào, coi nó như 1 khối rời rạc.
Xem trong danh sách gốc: x kề với những đỉnh nào còn sống thì nối lại và giảm số TPLT đi
*/
