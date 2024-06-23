//dp[i][j] là số lượng số có i chữ số và tổng các chữ số là j
//1. Số không có chữ số nào thì 0 có cách chọn: dp[0][i] = 0
//2. Số có tổng các chữ số bằng 0 thì cũng không có cách nào: dp[i][0] = 0, vì có i chữ số mà muốn tổng bằng 0 thì chỉ có thể là i số 0. đề không chấp nhận số 0 ở đầu
//3. Số có 1 chữ số và tổng các chữ số là x thì có 1 cách, chính là các số 1, 2, 3, ... , 9
/*Trong đó k là số được chèn thêm vào, 0<=k<=9
Ví dụ: Để tạo ra số có 3 chữ số có tổng các chữ số là 6 thì có 5 cách: số có 2 chữ số tổng chữ số là 6 chèn 0, số có 2 chữ só có tổng các chữ số là 5 chèn thêm số 1, v.v...*/
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX_N = 101;      // Số chữ số tối đa
const int MAX_SUM = 50005;  // Tổng các chữ số tối đa

int dp[MAX_N][MAX_SUM] = {};

int main() {
    for (int i = 1; i <= 9; ++i) dp[1][i] = 1; 
    for (int i = 2; i < MAX_N; ++i) {  // i là số chữ số
        for (int j = 0; j <= 9; ++j) { // j là chữ số đang chèn vào
            for (int k = j; k < MAX_SUM; ++k) { // k là tổng các chữ số
                dp[i][k] += dp[i - 1][k - j];
                dp[i][k] %= MOD;
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
