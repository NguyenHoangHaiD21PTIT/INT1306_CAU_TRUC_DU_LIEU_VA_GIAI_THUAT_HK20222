#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, s, q, cnt = 1;
    while (cin >> c >> s >> q && (c != 0 || s != 0 || q != 0)) {
        if (cnt > 1) cout << "\n";
        cout << "Case #" << cnt++ << "\n";
        int d[c + 5][c + 5];
        for (int i = 1; i <= c; i++) {
            for (int j = 1; j <= c; j++) d[i][j] = 1e9;
            d[i][i] = 0; 
        }
        while (s--) {
            int x, y, w;
            cin >> x >> y >> w;
            d[x][y] = w;
            d[y][x] = w;
        }
        for (int k = 1; k <= c; k++) {
            for (int i = 1; i <= c; i++) {
                for (int j = 1; j <= c; j++) d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
            }
        }
        while (q--) {
            int u, v; 
            cin >> u >> v;
            if (d[u][v] == 1e9) cout << "no path\n";
            else cout << d[u][v] << "\n";
        }
    }
}
//Link submit: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=989
