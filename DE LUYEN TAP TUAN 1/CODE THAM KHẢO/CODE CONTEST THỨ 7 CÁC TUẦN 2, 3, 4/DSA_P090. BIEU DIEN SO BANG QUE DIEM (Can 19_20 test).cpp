#include <bits/stdc++.h>
using namespace std;

const int m[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};//m[x] = y: Tạo ra số x thì cần y que diêm

int main() {
    int s, n; // s: số que diêm, n: số lượng chữ số được chọn
    cin >> s >> n;
    vector<int> a(n); // Tập các số được sử dụng
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());

    // Xử lý: dp[i] = x: Với i que diêm thì có thể tạo ra số dài nhất là x chữ số
    vector<int> dp(s + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= s; ++i) {
        for (int x : a) {
            if (i >= m[x] && dp[i - m[x]] != -1) dp[i] = max(dp[i], dp[i - m[x]] + 1);
        }
    }

    // Tạo số lớn nhất từ các chữ số đã chọn
    string ans;
    while (s > 0) {
        for (int x : a) {
            if (s >= m[x] && dp[s] == dp[s - m[x]] + 1) {
                ans += to_string(x);
                s -= m[x];
                break;
            }
        }
    }

    sort(ans.begin(), ans.end(), greater<char>());
    while (!ans.empty() && ans[0] == '0') ans.erase(ans.begin());
    if (!ans.empty()) cout << ans;
    else cout << 0;
}
