#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, u, v;
    cin >> n >> u >> v;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<long long> p(n + 1, 0);
    //pre[i] là tính đến i - 1
    for (int i = 0; i < n; ++i) p[i + 1] = p[i] + a[i];
    cout << endl;
    deque<int> dq;               
    long long ans = LLONG_MIN; 
    for (int i = u; i <= n; ++i) { //deque lưu các chỉ số của p front()_dq  ... back()_dq
        // i - 1: end, j: start --> len = i - j <= v --> j >= i - v --> j < i - v thì dãy dài quá v rồi
        while (!dq.empty() && dq.front() < i - v) dq.pop_front();
        // Thêm j = i - u (biên phải cửa sổ)
        // Đầu stack a < b < c < d ... cuối stack (Đầu dq)
        // 2. End tại i - 1, dài u, i - st = u --> st = i - u. 
        // Giả sử deque front ... a < b < c < d ... back. Ta có một phần tử e cần thêm vào cuối, sao cho vẫn đảm bảo trật tự tăng
        // Hiển nhiên phải loại bỏ các phần tử ở cuối deque mà lớn hơn hoặc bằng e. Nôm na là để các số trong dq luôn tăng dần và nhỏ nhất có thể
        int j = i - u;
        while (!dq.empty() && p[dq.back()] >= p[j]) dq.pop_back();
        dq.push_back(j);
        if (!dq.empty()) ans = max(ans, p[i] - p[dq.front()]);
    }
    cout << ans;
}
