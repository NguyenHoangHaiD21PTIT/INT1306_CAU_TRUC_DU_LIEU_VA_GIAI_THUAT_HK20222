#include <bits/stdc++.h>
using namespace std;
int main(){
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    int ans = m; 
    // Duyệt qua mọi vị trí bắt đầu i trong s
    for (int i = 0; i <= n - m; ++i) {
        int cnt = 0; // Đếm số ký tự khác nhau tại vị trí i
        for (int j = 0; j < m; ++j) {
            if (s[i + j] != t[j]) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans;
}
