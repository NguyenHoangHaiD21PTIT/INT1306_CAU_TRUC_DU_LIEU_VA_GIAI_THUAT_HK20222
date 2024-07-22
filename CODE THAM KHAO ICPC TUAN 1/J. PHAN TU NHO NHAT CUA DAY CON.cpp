#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int left[n], right[n];
    stack<int> s;
    //Tìm phần tử bên trái đầu tiên bé hơn
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (s.empty()) left[i] = -1;
        else  left[i] = s.top();
        s.push(i);
    }
    //Tìm phần tử bên phải đầu tiên bé hơn
    while (!s.empty()) s.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (s.empty()) right[i] = n;
        else  right[i] = s.top();
        s.push(i);
    }
    //Như vậy, a[i] sẽ là min trong dãy con liên tiếp từ [l[i] + 1; r[i] - 1]. Nói cách khác, a[i] là min trong dãy con liên tiếp dài r[i] - 1 - l[i] - 1 + 1
    vector<int> b(n, -1e9);
    for (int i = 0; i < n; i++) {
        int length = right[i] - left[i] - 1;
        b[length - 1] = max(b[length - 1], a[i]);
    }
    //b[i] = x: x là số lớn nhất trong tất cả các min của các cửa sổ trượt độ dài là x
    for (int i = n - 2; i >= 0; --i) b[i] = max(b[i], b[i + 1]);
    //Nhận xét: Dãy con độ dài X chắc chắn là dãy con của 1 trong các cửa sổ dài X + 1.
    //Vì vậy, ta sẽ trích xuất substr dài x từ các dãy con độ dài X + 1 mà chứa phần tủ lớn nhất trong số min của các cửa sổ dài X + 1
    for(int i = 0;i<n;i++) cout<<b[i]<<" ";
}
