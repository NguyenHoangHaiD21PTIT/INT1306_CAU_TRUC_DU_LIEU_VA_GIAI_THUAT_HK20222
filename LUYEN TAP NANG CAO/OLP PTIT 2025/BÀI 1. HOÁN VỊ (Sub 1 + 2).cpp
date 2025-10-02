#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> P(n);
    for (int i = 0; i < n; i++) cin >> P[i];
    while (m--) {
        int x, y;
        cin >> x >> y;
        vector<int> Q = P;
        swap(Q[x], Q[y]);
        vector<bool> vis(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                int cur = i;
                while (!vis[cur]) {
                    vis[cur] = true;
                    cur = Q[cur];
                }
            }
        }
        cout << cnt << "\n";
    }
}
