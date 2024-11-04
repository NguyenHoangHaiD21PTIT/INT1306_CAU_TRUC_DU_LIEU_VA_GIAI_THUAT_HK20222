#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7; 
int main() {
    int n; 
    cin >> n; 
    int a[n][5]; 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) cin >> a[i][j]; 
    }
    map<long long, int> cnt[6]; 
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << 5); mask++) {
            vector<int> subset;
            for (int j = 0; j < 5; ++j) {
                if (mask & (1 << j)) subset.push_back(a[i][j]); 
            }
            sort(subset.begin(), subset.end()); 
            long long val = 0, power = 1; 
            for (int j = 0; j < subset.size(); ++j) { // Kĩ thuật Hashing
                val = val * power + subset[j]; 
                power *= MOD; 
            }
            cnt[subset.size()][val]++; // Đếm số lượng tổ hợp với kích thước tương ứng
        }
    }
    long long tol = (long long)n * (n - 1) / 2; // Tổng số cặp học sinh
    long long inval = 0; // Số cặp học sinh không hợp nhau
    for (int i = 1; i <= 5; ++i) {
        for (const auto& ele : cnt[i]) {
            long long x = 1LL * ele.second * (ele.second - 1) / 2; 
            if (i % 2 == 1) inval += x;
            else  inval -= x;
        }
    }
    cout << (tol - inval); 
}
