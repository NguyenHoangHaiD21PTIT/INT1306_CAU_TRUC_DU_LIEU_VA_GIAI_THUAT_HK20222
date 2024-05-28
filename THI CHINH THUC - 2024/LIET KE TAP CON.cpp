#include <bits/stdc++.h>
using namespace std;

int n, ok, a[100];
vector<pair<string, int>> v; // Khai báo biến toàn cục

void kt() {
    for (int i = 0; i < n; i++) a[i] = 0;
}

void sinh() {
    int i = n - 1;
    while (i >= 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == -1) ok = 0;
    else a[i] = 1;
}

bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
    if (p1.second != p2.second) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main() {
    cin >> n;
    int k; cin >> k;

    kt();
    ok = 1;

    int b[n];
    for (int i = 0; i < n; i++) cin >> b[i];

    // Sinh các tổ hợp
    while (ok == 1) {
        int tong = 0;
        string s = "";

        // Tính tổng và tạo chuỗi tổ hợp
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                tong += b[n - i - 1];  // Tính tổng các phần tử theo mảng nhị phân
                s += to_string(n - i) + " "; // Tạo chuỗi tổ hợp
            }
        }

        // Nếu tổng nhỏ hơn k, thêm vào vector `v`
        reverse(s.begin(), s.end());
        if (tong < k&&s!="") v.push_back({s.substr(1), tong});

        // Tạo tổ hợp tiếp theo
        sinh();
    }

    // Sắp xếp vector `v` sử dụng hàm cmp
    sort(v.begin(), v.end(), cmp);

    // Xuất các tổ hợp đã sắp xếp
    for (auto p : v) {
        cout << p.first << endl; // In chuỗi tổ hợp trước
        cout << "Sum = " << p.second << endl; // In tổng sau
    }

    return 0;
}