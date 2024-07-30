#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Kiểm tra nếu tất cả các số đều giống nhau
    bool all_equal = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[0]) {
            all_equal = false;
            break;
        }
    }

    if (all_equal) {
        cout << "Lo nang roi" << endl;
        return 0;
    }

    // Kiểm tra nếu mảng đã sắp xếp theo thứ tự tăng dần
    bool is_sorted = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        cout << "Lo nang roi" << endl;
        return 0;
    }

    // Xử lý tìm hiệu lớn nhất
    int max_so_far = a[0];
    int max_diff = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] < max_so_far) max_diff = max(max_diff, max_so_far - a[i]);
        max_so_far = max(max_so_far, a[i]);
    }
    cout << max_diff << endl;
}
