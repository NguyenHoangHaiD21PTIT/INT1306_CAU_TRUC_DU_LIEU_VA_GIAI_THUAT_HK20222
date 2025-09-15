#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    unordered_map<ll, int> tot; //tot[A] = B: Tức là có B cặp (i, j) phân biệt mà A[i] + A[j] = B
    vector<unordered_map<ll, int>> inc(n); //inc[i][s]: Tức là số cặp(i, j) có tổng bằng S mà i đã tham gia
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j) {
            ll s = a[i] + a[j];
            ++tot[s];
            ++inc[i][s];
            ++inc[j][s];
        }
    }
    int ans = 0;
    for (int p = 0; p < n; ++p) {
        long long T = 3LL * a[p]; //3.A[p] = A[i] + A[j] + A[k]? Có tồn tại bộ ba số (i, j, k) hay không
        bool ok = false;
        for (int i = 0; i < n && !ok; ++i) {
            // Chọn A[i] là một số, thế thì sẽ còn lại A[j] + A[k] = 3.A[p] - A[i] = T - a[i] = s
            // Hỏi có bao nhiêu cặp số có tổng bằng s mà không sử dụng A[i]
            // Bài toán ngược: 
            // Đếm số cặp có tổng bằng S (Tập to) <Chính là tot[S]> - Số cặp có tổng bằng S mà A[i] tham gia <Không hợp lệ, là inc[i][S]>
            int valid = tot[T - a[i]] - inc[i][T - a[i]];
            if (valid > 0) ok = true;
        }
        if (ok) ++ans;
    }
    cout << ans;
}
