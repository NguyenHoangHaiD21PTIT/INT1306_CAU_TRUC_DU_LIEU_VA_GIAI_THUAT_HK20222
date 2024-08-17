#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) l[i] = 0;
        else l[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) r[i] = n - 1;
        else  r[i] = st.top() - 1;
        st.push(i);
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) res = max(res, (long long)a[i] * (r[i] - l[i] + 1));
    cout << res;
}
/*Hiểu là: Đề bài yêu cầu: Xét mọi dãy con liên tiếp, mỗi dãy con lấy phần tử nhỏ nhất nhân với chiều dài dãy con đó
Mà mỗi phần tử đều là min của dãy con liên tiếp nào đó --> Vét cạn kiểu mới: Mỗi phần tử, ta sẽ xem nó là min của những dãy con liên tiếp nào, rồi lấy phần tử đó * chiều dài dãy con đó
Đề bài yêu cầu: Lấy max. Vậy thì mỗi phần tử, ta chỉ cần xem nó là min của dãy con liên tiếp dài nhất nào. Rồi lấy max những phép tính đó.
*/
