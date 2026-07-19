#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p3(ll n) { 
    if (n < 3) return -1; // Vì A >= 1 nên 3^A phải >= 3
    int res = 0;
    while (n % 3 == 0) {
        n /= 3;
        res++;
    }
    return (n == 1) ? res : -1;
}

int main() {
    ll n, p5 = 1; 
    cin >> n;
    for (int b = 1; b <= 26; b++) {
        p5 *= 5;
        if (n > p5) {
            ll r = n - p5;
            ll a = p3(r);
            if (a != -1) {
                cout << a << " " << b;
                return 0;
            }
        } else break; 
    }
    cout << -1;
    return 0;
}
/*
3^A < 10^18 --> A < log3(10^18) = 37.7
5^B < 10^18 --> B < log5(10^18) = 25.7
Cho B chạy từ 1 đến 26. Với mỗi B, tính 5^B, rồi lấy N - 5^B xem có ra luỹ thừa của 3 không
Để tránh TLE, ta lấy nguyên biến dùng lại chính kết quả luỹ thừa trước đó
*/