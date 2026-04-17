#include <bits/stdc++.h>
using namespace std;
using d = double;

d f(d A, d B, d C, d x){
    return A * x * x * x + B * x - C;
}

d sol(d A, d B, d C){
    d l = 0, r = 1e9; d mid;
    while (r - l > 1e-7){
        mid = (l + r) / 2;
        if (f(A, B, C, mid) * f(A, B, C, l) <= 0) r = mid;
        else l = mid;
    }
    return (l + r) / 2;
}

int main(){
    int t; cin >> t;
    while (t--){
        d A, B, C; cin >> A >> B >> C;
        cout << fixed << setprecision(4) << sol(A, B, C) << "\n";
    }
}
/*Nhận xét: f(x) = Ax^3 + Bx + C --> f'(x) = 3Ax^2 + B > 0 do A, B, C > 0 --> Hàm đồng biến trên R
Định lý về hàm số liên tục: f(x) liên tục trên [a, b] và f(a).f(b) < 0 thì tồn tại c trong (a, b) sao cho f(c) = 0
*/
