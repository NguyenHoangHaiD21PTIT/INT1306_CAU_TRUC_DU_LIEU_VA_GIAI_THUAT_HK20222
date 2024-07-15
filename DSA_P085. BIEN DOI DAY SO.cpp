#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long a[n], b[n];
        for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];//Giá trị và chi phí thay thế
        //dp[i][0]: Chi phí giữ nguyên phần tử thứ i
        //dp[i][1]: Chi phí thay đổi phần tử thứ i
        long long dp[n + 5][2] = {};
        dp[0][0] = 0; 
        dp[0][1] = b[0]; 
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
                dp[i][0] = dp[i - 1][1];
            } else {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
            }
        }
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
    return 0;
}
/*
3

3

2 4

2 1

3 5

3

2 3

2 10

2 6

4

1 7

3 3

2 6

1000000000 2
*/
