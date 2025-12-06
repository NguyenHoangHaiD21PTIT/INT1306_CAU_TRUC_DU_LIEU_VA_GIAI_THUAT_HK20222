#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int n, q;
vector<int> a; vector<ll> f; // f[i]: chi phí nhỏ nhất để đến vị trí i

void solve() {
    int s, t, k;
    cin >> s >> t >> k;
    s--; t--; 
    if (s == t) { 
        cout << a[s] << "\n"; 
        return; 
    }
    if (s > t) swap(s, t);
    //Bước 1: Khởi tạo trạng thái đầu
    deque<int> dq; 
    f[s] = a[s]; dq.push_back(s);
    //Bước 2: Dùng dq để tìm chi phí nhỏ nhất. Đầu dq là trái, cuối dq là bên phải
    //Đảm bảo dq luôn tăng dần
    for (int i = s + 1; i <= t; ++i) {
        while (!dq.empty() && dq.front() < i - k) dq.pop_front();//Xoá các trạng thái không còn khả dụng
        f[i] = f[dq.front()] + a[i];//Cập nhật chi phí nhỏ nhất để đến vị trí i
        while (!dq.empty() && f[dq.back()] >= f[i]) dq.pop_back();//Đuổi hết những thằng "đắt" hơn f[i] ra khỏi hàng, và vị trí cuối sẽ cho f[i]
        dq.push_back(i);
    }
    cout << f[t] << "\n";
}

int main() {
    string s; cin >> n >> q >> s;
    a.resize(n); f.resize(n);
    for(int i = 0; i < n; ++i) a[i] = s[i] - '0';
    while(q--) solve();
}
