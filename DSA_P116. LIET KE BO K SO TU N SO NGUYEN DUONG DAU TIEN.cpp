#include <bits/stdc++.h>
using namespace std;

void in(vector<int> &vt) {
    for(int x : vt) cout << x << " ";
    cout << endl;
}

void Try(int i, int j, int n, int k, vector<int> &vt) {
    if(i > k) {
        in(vt);
        return;
    }
    for(int x = j; x <= n; x++) {
        vt.push_back(x);
        Try(i+1, x, n, k, vt);
        vt.pop_back();
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vt;
    Try(1, 1, n, k, vt);
}

int main() {
    solve();
    return 0;
}
/*ĐỀ BÀI
Cho hai số nguyên dương n và k (k ≤ n). 
Hãy liệt kê các bộ k số từ n số nguyên dương đầu tiên thoả mãn tính chất: các số từ trái sang phải có thể trùng nhau và có thứ tự không giảm. 
Ví dụ với n = 3 và k = 2 thì các bộ thoả mãn là: {1,1} {1,2} {1,3} {2,2} {2,3} {3,3}
Với n = 3 và k = 3 thì ta có kết quả như trong test ví dụ. 

Input
Chỉ có 1 dòng ghi 2 số n và k (1 < k ≤ n ≤ 12).

Output
Ghi ra màn hình lần lượt các bộ k số theo mô tả đề bài, mỗi kết quả trên một dòng, các số cách nhau một khoảng trống.

Ví dụ

Input
3 3

Output
1 1 1
1 1 2
1 1 3
1 2 2
1 2 3
1 3 3
2 2 2
2 2 3
2 3 3
3 3 3
*/
