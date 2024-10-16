#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int BIT[MAXN][MAXN]; 
vector<pair<int, int>> points; 

void update(int x, int y, int val) {
    for (int i = x; i < MAXN; i += i & -i) {
        for (int j = y; j < MAXN; j += j & -j) BIT[i][j] += val;
    }
}

int query(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) res += BIT[i][j];
    }
    return res;
}

int get(int a, int b, int u, int v) {
    return query(u, v) - query(a - 1, v) - query(u, b - 1) + query(a - 1, b - 1);
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            update(x, y, 1); 
        } else if (type == 2) {
            int a, b, u, v;
            cin >> a >> b >> u >> v;
            int k = get(a, b, u, v); 
            long long res = 1LL * k * (k - 1) * (k - 2) / 6;
            cout << res << endl;
        }
    }
}
