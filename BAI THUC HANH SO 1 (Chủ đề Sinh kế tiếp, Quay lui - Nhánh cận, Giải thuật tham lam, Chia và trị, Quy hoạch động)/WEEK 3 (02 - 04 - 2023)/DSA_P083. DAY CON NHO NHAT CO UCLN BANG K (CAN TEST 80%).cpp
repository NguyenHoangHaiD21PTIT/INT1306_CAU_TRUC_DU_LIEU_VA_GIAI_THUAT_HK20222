#include <bits/stdc++.h>
using namespace std;

long long solve(long long a[], long long l, long long r, long long k) {
    long long ans = LLONG_MAX;
    // Giới hạn chiều dài đoạn con tối đa là 10
    long long len = r - l + 1;
    if(len>10000) len = 10;
    for (int i = l; i <= l + len; i++) {
        long long res = a[i];
        for (int j = i + 1; j < i + len && j <= r; j++) {
            res = __gcd(res, a[j]);
            if (res == k) {
                ans = min(ans, (long long)(j - i + 1));
                break;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long a[100005];
        for (long long i = 1; i <= n; i++) cin >> a[i];
        vector<pair<long long, long long>> range; // Chỉ quét UCLN trong các khoảng [l; r] có trong vector này
        long long ans = LLONG_MAX;
        long long l = -1, r = -1;
        for (long long i = 1; i <= n; i++) {
            if (a[i] == k) {
                ans = 1; // Tìm thấy phần tử bằng k
                break;
            } else if (a[i] % k == 0) {
                if (l == -1) l = r = i; // Nếu chưa có đoạn thì bắt đầu từ đây
                else r = i; // Nếu có đoạn rồi thì mở rộng nó ra
            } else {
                if (r != -1) {
                    range.push_back({l, r}); // Đoạn bị gãy thì ghi nhận đoạn trước đó vào
                    l = r = -1; // Reset các chỉ số
                }
            }
        }

        // Thêm đoạn cuối cùng nếu có
        if (r != -1) range.push_back({l, r});

        if (ans != 1) {
            // Xử lý từng khoảng trong danh sách
            for (auto p : range) {
                long long l = p.first, r = p.second;
                ans = min(ans, solve(a, l, r, k));
            }
        }
        cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    }
    return 0;
}
