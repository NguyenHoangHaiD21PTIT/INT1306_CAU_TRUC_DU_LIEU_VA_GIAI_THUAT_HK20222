#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        long long A[N], B[N];
        for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
        long long dp[N][3];
        for(int i = 0; i < 3; i++) dp[0][i] = LLONG_MAX;
        dp[0][0] = 0; 
        dp[0][1] = B[0]; 
        dp[0][2] = 2 * B[0];
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = LLONG_MAX; 
                for (int k = 0; k < 3; k++) {
                    if (A[i] + j != A[i - 1] + k) dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * B[i]);
                }
            }
        }
        cout << min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}) << endl;
    }
}
