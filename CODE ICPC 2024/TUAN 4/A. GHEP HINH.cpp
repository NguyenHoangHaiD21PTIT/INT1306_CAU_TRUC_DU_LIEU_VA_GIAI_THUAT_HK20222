#include <bits/stdc++.h>
using namespace std;

long long ktcp(long long a) { // Kiểm tra xem 1 số có phải số chính phương không
    long long b = sqrt(a);
    if (b * b == a) return b;
    return 0;
}

int main() {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    long long s = a * b + c * d + e * f;
    long long y = ktcp(s);// Nếu tổng diện tích không phải số chính phương thì không ghép được
    if (y == 0) {
        cout << "0" << endl;
    } else {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        if (e > f) swap(e, f);
        //TH1: 3 HCN chồng ngang lên nhau
        if (b == d && d == f && f == y) {
            cout << b;
        } else { // Sắp xếp theo chiều dài tăng dần
            if (d > b) { swap(a, c); swap(b, d); }
            if (f > b) { swap(a, e); swap(b, f); }
            if (b == y) {
                if (c + e == y || d + f == y || c + f == y || d + e == y) cout << y;
                else cout << "0";
            } else {
                cout << "0";
            }
        }
    }
}
