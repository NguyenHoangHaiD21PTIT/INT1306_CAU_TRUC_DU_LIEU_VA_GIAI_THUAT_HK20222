#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    stack<int> st;
    int cnt[60006] = {0}; // Khởi tạo mảng cnt có tất cả các giá trị bằng 0

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        while (!st.empty() && x > st.top()) {
            cnt[st.top()]--;
            ans++;
            st.pop();
        }

        if (!st.empty()) {
            if (x == st.top()) {
                if (st.size() > cnt[x]) 
                    ans += cnt[x] + 1;
                else 
                    ans += cnt[x];
            } else {
                ans++;
            }
        }

        st.push(x);
        cnt[x]++;
    }

    cout << ans << endl;
    return 0;
}
