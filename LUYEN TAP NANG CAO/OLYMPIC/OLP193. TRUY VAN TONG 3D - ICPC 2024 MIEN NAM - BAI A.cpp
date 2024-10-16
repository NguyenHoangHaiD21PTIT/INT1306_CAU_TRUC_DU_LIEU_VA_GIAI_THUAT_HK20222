#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 101; 
int n; 
ll BIT[MAXN][MAXN][MAXN]; 
ll A[MAXN][MAXN][MAXN]; 

void update(int x, int y, int z, ll p) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= n; j += j & -j) {
            for (int k = z; k <= n; k += k & -k) BIT[i][j][k] += p;
        }
    }
}

ll getSum(int x, int y, int z) {
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            for (int k = z; k > 0; k -= k & -k) res += BIT[i][j][k];
        }
    }
    return res;
}

ll query(int x1, int y1, int z1, int x2, int y2, int z2) {
    return getSum(x2, y2, z2) 
           - getSum(x1 - 1, y2, z2) 
           - getSum(x2, y1 - 1, z2) 
           - getSum(x2, y2, z1 - 1) 
           + getSum(x1 - 1, y1 - 1, z2) 
           + getSum(x1 - 1, y2, z1 - 1) 
           + getSum(x2, y1 - 1, z1 - 1) 
           - getSum(x1 - 1, y1 - 1, z1 - 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(BIT, 0, sizeof(BIT));
        memset(A, 0, sizeof(A));
        int m;
        cin >> m;
        while (m--) {
            string type;
            cin >> type;
            if (type == "UPDATE") {
                int x, y, z;
                ll w;
                cin >> x >> y >> z >> w;
                ll diff = w - A[x][y][z];
                A[x][y][z] = w;
                update(x, y, z, diff); 
            } else if (type == "QUERY") {
                int x1, y1, z1, x2, y2, z2;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                cout << query(x1, y1, z1, x2, y2, z2) << endl; 
            }
        }
    }
    return 0;
}
