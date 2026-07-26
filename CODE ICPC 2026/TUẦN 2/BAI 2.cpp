#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[25][25];

void dfs(int i, int j) { //DFS O ở biên
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] != 'O') return;
    a[i][j] = 'S'; 
    dfs(i + 1, j); dfs(i - 1, j); dfs(i, j + 1); dfs(i, j - 1);
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> a[i][j];
        // Quét 4 cạnh của ma trận
        for (int i = 0; i < n; i++) { dfs(i, 0); dfs(i, m - 1); }
        for (int j = 0; j < m; j++) { dfs(0, j); dfs(n - 1, j); }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << (a[i][j] == 'S' ? 'O' : 'X') << " ";
            cout << "\n";
        }
    }
}