#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    double dp[101][101][101] = {}; // dp[a][b][c] = kỳ vọng số bước còn lại
    for (int a = 99; a >= 0; --a) {
        for (int b = 99; b >= 0; --b) {
            for (int c = 99; c >= 0; --c) {
                int s = a + b + c;
                double ans = 1.0; 
                if (a > 0) ans += (double)a / s * dp[a + 1][b][c];
                if (b > 0) ans += (double)b / s * dp[a][b + 1][c];
                if (c > 0) ans += (double)c / s * dp[a][b][c + 1];
                dp[a][b][c] = ans;
            }
        }
    }
    cout << fixed << setprecision(6) << dp[A][B][C] << '\n';
}
