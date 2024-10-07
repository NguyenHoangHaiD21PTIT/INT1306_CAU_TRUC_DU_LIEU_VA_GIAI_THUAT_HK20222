#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; 
    cin >> T;
    for(int t = 1;t<=T;t++) {
        int N; 
        cin >> N;
        int dp[N + 2][4] = {};//dp[i][0]: tổng điểm tối đa khi chọn hoạt động A ngày thứ i
        for (int i = 1; i <= N; i++) {
            int ai, bi, ci;
            cin >> ai >> bi >> ci;
            if (i == 1) {
                dp[i][0] = ai;
                dp[i][1] = bi;
                dp[i][2] = ci;
            } else {
                dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + ai; // Chọn A sau B hoặc C
                dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + bi; // Chọn B sau A hoặc C
                dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + ci; // Chọn C sau A hoặc B
            }
        }
        int res = max({dp[N][0], dp[N][1], dp[N][2]});
        cout << "Case #"<<t<<": "<<res << endl;
    }
}
