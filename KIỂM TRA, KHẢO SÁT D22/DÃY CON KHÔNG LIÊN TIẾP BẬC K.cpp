#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n, k; cin >> n >> k;
    vector<ll> a(n + 1), s(n + 1, 0); // Mảng tổng cộng dồn
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    vector<ll> dp(n + 1, 0), f(n + 1, 0); 
    // Khởi tạo cơ sở
    f[0] = 0; // Đặt f[x] = dp[x - 1] - s[x] 
    for (int i = 1; i <= n; i++) {
        // Lựa chọn 1: Không chọn phần tử thứ i
        dp[i] = dp[i - 1];
        // Lựa chọn 2: Chọn một đoạn tối đa K-1 phần tử kết thúc tại i
        ll max_f = -1e18; 
        for (int j = 1; j < k && i - j >= 0; j++) max_f = max(max_f, f[i - j]);
        dp[i] = max(dp[i], s[i] + max_f);
        f[i] = dp[i - 1] - s[i];
    }
    cout << dp[n];
}
/*
Cuối - Đầu + 1 = j --> i - Đầu + 1 = j --> i - j + 1 = Đầu
Tại vị trí i, ta sẽ chọn j phân tử liên tiếp kết thúc tại i, tức là từ i - j + 1 đến i.
Để đoạn trên không dính đến các số trước đó (Phạm luật K phần tử liên tiếp), ta phải hi sinh phàn tử ngay trước nó (i - j)
Tổng = (Kỉ lục tốt nhất đến điểm ngắt trước đó) + (Tổng của đoạn vừa chọn)
     = dp[i - j - 1] + s[i] - s[i - j]
Vì đang xét tại vị trí i nên i đứng im, j thay đổi từ 1 đến K-1, ta có:
    = max(dp[i - j - 1] + s[i] - s[i - j]) 
     = s[i] + max(dp[i - j - 1] - s[i - j]) 
     = s[i] + max(f[i - j]) 
Vậy ta chỉ cần tìm trong các j từ 1 đến K-1, giá trị lớn nhất của f[i - j] để cộng với s[i] là được.
*/
