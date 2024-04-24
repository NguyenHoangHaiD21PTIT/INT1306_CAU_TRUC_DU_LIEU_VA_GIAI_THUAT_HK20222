#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 0, res = 0;
    stack<pair<char, int>> st;
    st.push({'*', 0}); // Để tránh stack rỗng

    for (char i : s) {
        if (!st.empty() && ((i == ')' && st.top().first == '(') || (i == ']' && st.top().first == '['))) {
            // Đóng và có mở tương ứng --> Là dãy ngoặc đúng --> Xóa dấu mở ngoặc cùng cấp
            st.pop();
            if (!st.empty()) {
                res = max(res, cnt - st.top().second);
                // Như vậy, đỉnh stack bây giờ lưu dấu mở ngoặc và số dấu ngoặc vuông mở khi không xét đến dấu mở cùng cấp
            }
        } else { // Gặp mở hoặc đóng không khớp thì push vào
            if (i == '[') cnt++;
            st.push({i, cnt});
        }
    }
    cout << res << endl;
    return 0;
}
