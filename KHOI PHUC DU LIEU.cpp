#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int m, k;
int dp[5001][101]; // dp[c][d] là số cách chọn trong c cột đầu và số ô chia k dư d

int main() {
    cin >> m >> k;
    dp[0][0] = 1;//Có một cách để chọn 0 ô trong 0 cột sao cho tổng số ô được chọn chia hết cho k
    for (int c = 1; c <= m; ++c) {
        int temp[101] = {0};
        for (int d = 0; d < k; ++d) {
            if (dp[c-1][d] == 0) continue;
            for (int S = 0; S <= 7; ++S) {
                int bits = __builtin_popcount(S); // Số bit 1 trong cấu hình S
                if (bits == 3) continue; // Không cho phép chọn cả 3 ô cùng lúc
                // Tính dư mới khi thêm cấu hình S
                int new_d = (d + bits) % k;
                temp[new_d] = (temp[new_d] + dp[c-1][d]) % MOD;
            }
        }
        for (int d = 0; d < k; ++d) dp[c][d] = temp[d];
    }
    int result = (dp[m][0] - 1 + MOD) % MOD; // Trừ đi 1 vì không chọn ô nào
    cout << result << endl;
    return 0;
}