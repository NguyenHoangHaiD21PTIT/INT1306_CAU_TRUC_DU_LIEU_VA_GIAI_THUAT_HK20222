#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 9;
const int MAXN = 1001;
int n, m, k;
int a[MAXN], b[MAXN], dp[11][MAXN][MAXN], pre[11][MAXN][MAXN]; 
//dp[i][j][l] = số cách chọn i người đầu tiên (i ≤ K) từ a[1..j] và b[1..l] sao cho ghép cặp i-1 người trước đã thỏa điều kiện, và người thứ i vừa chọn thỏa A > B.

void solve() {
    int ans = 0;
    for (int i = 1; i <= k; i++) { //Số cặp đấu đang xét
        for (int j = 1; j <= n; j++) { //j: Số lượng người đã chọn từ A
            for (int l = 1; l <= m; l++) { // l: Số lượng người đã chọn từ B
                if (a[j] > b[l]) { //Mạnh hơn thì mới ghép
                    if (i == 1) dp[i][j][l] = 1;
                    else dp[i][j][l] = pre[i - 1][j - 1][l - 1];
                    // Muốn có cặp thứ i là (a[j], b[l]), ta phải chọn i - 1 cặp từ j - 1 người đầu A và l - 1 người đầu B trước đó.
                }
                pre[i][j][l] = (pre[i][j - 1][l] + dp[i][j][l]) % MOD;
                if (i == k)  ans = (ans + dp[i][j][l]) % MOD;
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= m; l++)  pre[i][j][l] = (pre[i][j][l] + pre[i][j][l - 1]) % MOD;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + m + 1);
    solve();
}
