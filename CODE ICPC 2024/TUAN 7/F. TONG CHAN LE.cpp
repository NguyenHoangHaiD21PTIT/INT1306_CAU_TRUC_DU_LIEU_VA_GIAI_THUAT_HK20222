#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    int N, p;
    cin >> N >> p;
    int A[100];  
    for (int i = 0; i < N; i++) cin >> A[i];
    int dp[2][2] = {0};  // dp[i][0]: tổng chẵn, dp[i][1]: tổng lẻ
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        int num = A[i-1];
        int cur_even = dp[(i-1)%2][0];
        int cur_odd = dp[(i-1)%2][1];
        if (num % 2 == 0) {
            //Nếu phần tử hiện tại chẵn, thì thêm phần tử này vào tập các tổng đang là chẵn thì vẫn ra chẵn (x tập không có phần tử hiện tại, x tập kia thêm phần tử hiện tại là gấp đôi)
            dp[i%2][0] = (cur_even * 2) % MOD;
            dp[i%2][1] = (cur_odd * 2) % MOD;
        } else {
            dp[i%2][0] = (cur_even + cur_odd) % MOD;
            dp[i%2][1] = (cur_even + cur_odd) % MOD;
        }
    }
    cout << dp[N%2][p];
}
