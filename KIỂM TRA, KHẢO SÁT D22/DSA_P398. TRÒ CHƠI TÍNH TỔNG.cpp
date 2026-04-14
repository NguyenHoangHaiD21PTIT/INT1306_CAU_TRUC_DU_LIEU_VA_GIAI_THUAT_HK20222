#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[5005];
ll dp[5005][5005]; 

int main() {
    int n; cin >> n; 
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < n; i++) dp[i][i] = a[i];
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1; 
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    ll diff = dp[0][n - 1];
    ll s1 = (sum + diff) / 2;
    ll s2 = sum - s1;
    cout << s1 << " " << s2;
}
/*Gọi dp[i][j] là chênh lệch lớn nhất giữa người đến lượt với đối thủ của mình khi xét các phần tử từ i đến j.
Người đến lượt có 2 lựa chọn.
1. Chọn số bên trái: Chọn a[i]. 
Khi đó, đối thủ sẽ được quyền chọn tiếp từ i + 1 đến j
Và vì cả 2 chơi tối ưu nên đối thủ sẽ tạo ra chênh lệch lớn nhất trên đoạn của mình, tức là dp[i + 1][j].
--> Chênh lệch khi chọn a[i] là a[i] - dp[i + 1][j]
2. Chọn số bên phải: Chọn a[j].
Khi đó, đối thủ sẽ được quyền chọn tiếp từ i đến j - 1. Tương tự.
3. Trường hợp cơ sở: Còn 1 số thì buộc phải chọn số đó.
Tí - Tèo = dp[0][n - 1], Tí + Tèo = sum.
4. Lập luận Toán học: Giả sử bây giờ là lượt của Tí trên đoạn [i ... j].
Tí quyết định bốc A[i]. Thế thì dp[i + 1][j] là điểm Tèo - điểm Tí trên đoạn còn lại
Xét trên toàn bộ đoạn con.
Chênh lệch của Tí = Tí - Tèo
                  = (A[i] + điểm Tí trên đoạn còn lại) - (điểm Tèo trên đoạn còn lại)
                  = A[i] - (điểm Tèo trên đoạn còn lại - điểm Tí trên đoạn còn lại) = A[i] - dp[i + 1][j]
*/
//Submit tại: https://cses.fi/problemset/task/1097/
