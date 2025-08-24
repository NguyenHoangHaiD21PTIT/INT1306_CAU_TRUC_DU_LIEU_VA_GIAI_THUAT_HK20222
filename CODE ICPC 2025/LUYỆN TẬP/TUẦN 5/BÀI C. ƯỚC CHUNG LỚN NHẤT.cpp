#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, p;

vector<pair<ll, int>> fct(ll x) {
    vector<pair<ll,int>> v;
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            int c = 0;
            while(x % i == 0) {
                x /= i; 
                c++; 
            }
            v.push_back({i, c});
        }
    }
    if(x > 1) v.push_back({x, 1});
    return v;
}

int main() {
    cin >> n >> p;
    ll q = 1;
    auto fac = fct(p);
    for(auto &u : fac) {
        ll r = u.first;
        int e = u.second;
        ll exp = e / n;
        for(int i = 0; i < exp; i++) q *= r;
    }
    cout << q;
}
//a[1] * a[2] * ... * a[N] = P (1)
//GCD cả dãy là Q --> Mỗi a[i] đều viết được dưới dạng Q * B[i]
//Tích (1) được biểu diễn thành: Q * B[1] * Q * B[2] * ... * Q * B[N] = P = Q^N * (B[1] * B[2] * ... * B[N]) = Q^N * B
//Vì GCD cả dãy A là Q nên GCD của dãy B là 1, nên tích dãy B không chia hết cho Q nữa.
//Bài toán trở thành tìm Q max để B chia hết cho Q^N
//Giả sử B = a^x * b^y * c^z. Để B chia hết cho Q^N thì Q^N cũng phải chứa các thừa số của B
//Q^N = a^x1 * b^y1 * c^z1 -->Q = [a ^ (x1 * N)] * [b ^ (y1 * N)] * [c ^ (z1 * N)]
//Nx1 <= x; Ny1 <= y; Nz1 <= z --> x1 <= x/N, y1 <= y/N, z1 <= z/N, do x1, y1, z1 nguyên nên phép chia chỉ lấy phần nguyên