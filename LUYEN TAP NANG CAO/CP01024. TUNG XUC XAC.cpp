//dp[i][j] là số cách tung i lần mà tổng điểm là j
//1. Không tung lần nào thì 0 có cách chọn: dp[0][i] = 0
//2. Tổng các lần tung bằng 0 thì cũng 0 cách: dp[i][0] = 0, vì tung i lần mà muốn tổng bằng 0 thì chỉ có thể là i lần lần nào cũng tung ra số 0 (Vô lí)
//3. Tung 1 lần và tổng điểm là x thì có 1 cách, chính là các số 1, 2, 3, 4, 5, 6
//Ví dụ: Để tung 3 lần có tổng điểm bằng 6 thì có cách: Tung 2 lần với tổng điểm 5 & lần 3 1 điểm v.v...*/
#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 22;      // Số lần tung tối đa
const int MAX_SUM = 122;  // Tổng điểm tối đa

long long dp[MAX_N][MAX_SUM] = {};

int main() {
    for (int i = 1; i <= 6; ++i) dp[1][i] = 1; 
    for (int i = 2; i < MAX_N; ++i) {  // i là lần tung
        for (int j = 1; j <= 6; ++j) { // j là số điểm mặt lần tung hiện tại
            for (int k = j; k < MAX_SUM; ++k) { // k là tổng điểm mong muốn
                dp[i][k] += dp[i - 1][k - j];
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
    return 0;
}