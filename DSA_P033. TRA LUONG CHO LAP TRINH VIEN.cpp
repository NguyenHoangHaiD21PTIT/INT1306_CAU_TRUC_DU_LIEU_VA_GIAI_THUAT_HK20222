#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<pair<int, int>> luong(n);  // Lưu khoảng lương của mỗi nhân viên
    set<int> mucLuong;  // Để lưu tất cả các mức lương khả dĩ 
    for (int i = 0; i < n; ++i) {
        cin >> luong[i].first >> luong[i].second;
        mucLuong.insert(luong[i].first);
        mucLuong.insert(luong[i].second);
    }
    int maxDongCode = 0;  // Biến lưu trữ tổng số dòng code đúng lớn nhất có thể đạt được
    for (int muc : mucLuong) {
        int tongDongCode = 0;
        for (auto khoang : luong) {
            if (muc < khoang.first) tongDongCode += x;
            else if (muc <= khoang.second) tongDongCode += y;
            else tongDongCode += z;
        } 
        maxDongCode = max(maxDongCode, tongDongCode);
    }  
    cout << maxDongCode << endl;
}
