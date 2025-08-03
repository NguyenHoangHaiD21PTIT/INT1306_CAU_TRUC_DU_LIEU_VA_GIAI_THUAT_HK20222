#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105, MAXV = 10005;
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;
    int S = accumulate(A.begin(), A.end(), 0);
    // dp[k][v]: tổng soda sẵn có tối đa khi chọn k chai có tổng dung tích v
    vector<vector<int>> dp(N + 1, vector<int>(MAXV, -1));
    dp[0][0] = 0; // chưa chọn chai nào, thể tích 0, soda 0
    //Cập nhật lượng soda lấy được nhiều nhất khi chọ k chai có tổng thể tích v
    for (int i = 0; i < N; ++i) { //Duyệt qua từng chai soda
        for (int k = N - 1; k >= 0; k--) { //Duyệt số chai đã chọn
            for (int v = 0; v <= 10000 - B[i]; v++) { //Duyệt thể tích
                if (dp[k][v] != -1) {
                    int new_v = v + B[i];
                    int new_soda = dp[k][v] + A[i];
                    dp[k + 1][new_v] = max(dp[k + 1][new_v], new_soda);
                }
            }
        }
    }
    int res_K = -1, res_T = INT_MAX;
    for (int k = 1; k <= N; ++k) {
        for (int v = S; v < MAXV; ++v) {
            if (dp[k][v] != -1) {
                int ans = S - dp[k][v]; //Lượng soda cần phải đổ thêm
                if (res_K == -1 || k < res_K || (k == res_K && ans < res_T)) {
                    //Nếu lần đầu, lấy ít chai hơn, cùng chai nhưng lượng chuyển đổi ít hơn
                    res_K = k;
                    res_T = ans;
                }
            }
        }
    }
    cout << res_K << " " << res_T << '\n';
}
