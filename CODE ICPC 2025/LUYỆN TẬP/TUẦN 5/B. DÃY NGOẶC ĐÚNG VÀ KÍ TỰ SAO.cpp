#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = s.size(), star = 0;
        // Tìm vị trí của dấu * trong xâu (Vì mỗi xâu chỉ có 1 dấu sao thôi)
        while (star < n && s[star] != '*') ++star;
        int res = 0;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (i == star) continue;
            if (s[i] == '(') st.push(i);
            else {
                if (st.empty()) continue; //Mở không có đóng --> Loại
                if (st.top() < star && star < i) ++res; //Mở có đóng tương ứng, nhưng mở trước dấu *, đóng sau dấu * --> 1 cặp hợp lệ
                st.pop();
            }
        }
        cout << res << endl;
    }
}
