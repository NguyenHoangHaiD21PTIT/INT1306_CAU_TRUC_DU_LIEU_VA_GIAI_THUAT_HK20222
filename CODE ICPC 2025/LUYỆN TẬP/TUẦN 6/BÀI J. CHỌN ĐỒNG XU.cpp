#include <bits/stdc++.h>
using namespace std;

double dp[101][101][101];
bool vis[101][101][101];

//Số bước cần thực hiện từ trạng thái (a, b, c)
double solve(int a, int b, int c) {
    if (a >= 100 || b >= 100 || c >= 100) return 0.0;
    if (vis[a][b][c]) return dp[a][b][c];
    vis[a][b][c] = true;
    int s = a + b + c; 
    double ans = 1.0;
    // a/s, b/s, c/s là xác suất chọn ra số đồng xu mỗi loại
    if (a) ans += (double)a / s * solve(a + 1, b, c);
    if (b) ans += (double)b / s * solve(a, b + 1, c);
    if (c) ans += (double)c / s * solve(a, b, c + 1);
    return dp[a][b][c] = ans;
}
int main() {
    int A, B, C; cin >> A >> B >> C;
    cout << setprecision(6) << solve(A, B, C);
}
