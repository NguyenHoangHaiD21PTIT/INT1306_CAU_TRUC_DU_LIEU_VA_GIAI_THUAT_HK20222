#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int, int>
const int N = 2e5+5, M = 1e3+5, MOD = 1e9+7, inf = 1e18;
int n, m, x, y, res, test, cnt, sum, k, d;
int h[N], vis[N], f[M][M], c[M][M], num[M][M], a1[M];
char a[M][M];
ii b[N];

int xr[4] = {-1, 0, 1, 0}, yr[4] = {0, 1, 0, -1};

void bfs(int u, int v, int id) {
    queue<ii> q;
    while (q.size()) q.pop();
    q.push({u, v});

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) c[i][j] = 0;

    c[u][v] = 1; f[id][0] = inf;

    while (q.size()) {
        ii s = q.front(); q.pop();
        int xx = s.first, yy = s.second;
        for (int i = 0; i < 4; ++i) {
            x = xx + xr[i]; y = yy + yr[i];
            if (x < 1 || x > n) continue;
            if (y < 1 || y > m) continue;
            if (c[x][y] || a[x][y] == '#') continue;
            c[x][y] = c[xx][yy] + 1;
            q.push({x, y});
            if (a[x][y] == 'A') f[id][num[x][y]] = c[x][y];
            else if (a[x][y] == 'D') f[id][0] = min(f[id][0], c[x][y]);
        }
    }
}

void try_() {
    int kt = 1;
    while (kt) {
        //for (int i = 1; i <= cnt; ++i) cout << a1[i] << ' '; cout << endl;
        kt = 0; sum = 0;
        for (int i = 1; i < cnt; ++i) {
            x = f[a1[i]][a1[i + 1]];
            --x;
            y = 0;
            if (f[a1[i + 1]][0] != inf && f[a1[i]][0] != inf) y = f[a1[i + 1]][0] + f[a1[i]][0] - 2;
            if (x == 0 && y == 0) break;
            if (x > 0 && y > 0) sum += min(x, y);
            else if (x > 0) sum += x;
            else sum += y;
            if (i == cnt - 1) res = min(res, sum);
        }
        for (int i = cnt - 1; i > 0; --i) if (a1[i] < a1[i + 1]) {
            x = inf; ++kt;
            for (int j = i + 1; j <= cnt; ++j)
                if (a1[j] > a1[i] && a1[j] < x) x = a1[j], y = j;
            swap(a1[i], a1[y]);
            reverse(a1 + i + 1, a1 + cnt + 1);
            break;
        }
        //for (int i = 1; i <= cnt; ++i) cout << a1[i] << ' '; cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    res = inf;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'A') b[++k] = {i, j}, num[i][j] = ++cnt;
        }
    if (cnt == 1) res = 0;
    else {
        for (int i = 1; i <= k; ++i) bfs(b[i].first, b[i].second, i);
        for (int i = 1; i <= cnt; ++i) a1[i] = i;
        try_();
    }
    cout << (res == inf ? -1 : res);
}
