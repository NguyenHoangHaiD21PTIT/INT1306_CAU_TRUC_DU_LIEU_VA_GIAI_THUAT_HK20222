#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, z;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B, C;
        cin >> A >> B >> C;
        
        char vs[A][B][C];
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                for (int k = 0; k < C; ++k) cin >> vs[i][j][k];
            }
            if(i<A - 1) cin.ignore();
        }
        
        int sx, sy, sz, ex, ey, ez;
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                for (int k = 0; k < C; ++k) {
                    if (vs[i][j][k] == 'S') sx = i, sy = j, sz = k;
                    else if (vs[i][j][k] == 'E') ex = i, ey = j, ez = k;
                }
            }
        }
        
        int f[31][31][31] = {};
        queue<Point> q;
        q.push({sx, sy, sz});
        f[sx][sy][sz] = 0;
        
        int dx[] = {-1, 1, 0, 0, 0, 0};
        int dy[] = {0, 0, -1, 1, 0, 0};
        int dz[] = {0, 0, 0, 0, -1, 1};
        bool found = false;
        
        while (!q.empty()) {
            Point u = q.front();
            q.pop();
            
            if (u.x == ex && u.y == ey && u.z == ez) {
                cout << f[ex][ey][ez] << endl;
                found = true;
                break;
            }
            
            for (int k = 0; k < 6; k++) {
                int ni = u.x + dx[k];
                int nj = u.y + dy[k];
                int nk = u.z + dz[k];
                
                if (ni >= 0 && ni < A && nj >= 0 && nj < B && nk >= 0 && nk < C && vs[ni][nj][nk] != '#') {
                    if (f[ni][nj][nk] == 0) { 
                        f[ni][nj][nk] = f[u.x][u.y][u.z] + 1;
                        q.push({ni, nj, nk});
                    }
                }
            }
        }
        
        if (!found) cout << -1 << endl;
    }
    
    return 0;
}
