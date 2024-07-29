#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> soQue = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; // soQue[i] = j: Biểu diễn số i cần j que diêm
    for (int i = 0; i < m; i++) cin >> a[i]; // Vector các số được sử dụng
    sort(a.begin(), a.end(), greater<int>());
    vector<string> dp(n + 1, "");
    for (int i = 1; i <= n; i++) { // Số que diêm
        for (int x : a) { // Số được sử dụng
            int queDiem = soQue[x];//Số que diêm để biểu diễn số x
            if (i >= queDiem) { // Nếu có đủ que diêm để tạo ra chữ số này và có thể tạo số mới
                string soMoi = to_string(x) + dp[i - queDiem];
                if (dp[i].empty() || soMoi.size() > dp[i].size() || (soMoi.size() == dp[i].size() && soMoi > dp[i])) dp[i] = soMoi;
            }
        }
    }
    cout << dp[n] << endl;
}
