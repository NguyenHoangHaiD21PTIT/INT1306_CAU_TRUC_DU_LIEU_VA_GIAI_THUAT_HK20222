#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
int main(){
    int dp[N], h[N], n, k; //dp[i]: Năng lượng tối thiểu để nhảy từ cột 1 đến cột N
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> h[i];
    dp[1] = 0; // Đứng ở điểm xuất phát thì đương nhiên không tốn năng lượng
    for (int i = 2; i <= n; i ++){
        dp[i] = 1e9;
        for (int j = 1; j <= k; j++){
            if (i - j >= 1) dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout << dp[n];
}
//Nguồn: https://oj.vnoi.info/problem/atcoder_dp_b
