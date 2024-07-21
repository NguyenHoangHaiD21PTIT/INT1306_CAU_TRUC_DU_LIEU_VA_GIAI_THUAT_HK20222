#include <bits/stdc++.h>
using namespace std;

// Phân tích thừa số nguyên tố
vector<pair<long long, int>> phanTichThuaSo(long long k) {
    vector<pair<long long, int>> thuaSo;
    for (long long d = 2; d * d <= k; ++d) {
        if (k % d == 0) {
            int dem = 0;
            while (k % d == 0) {
                k /= d;
                ++dem;
            }
            thuaSo.push_back({d, dem});
        }
    }
    if (k > 1) thuaSo.push_back({k, 1});
    return thuaSo;
}

// Hàm tính số lần xuất hiện của số nguyên tố p trong N!
long long dem(long long n, long long p) {
    long long dem = 0;
    while (n >= p) {
        dem += n / p;
        n /= p;
    }
    return dem;
}

// Hàm tính số nguyên M lớn nhất sao cho K^M là ước của N!
long long timMMax(long long n, long long k) {
    vector<pair<long long, int>> thuaSo = phanTichThuaSo(k);
    long long minM = LLONG_MAX;
    for (auto& ts : thuaSo) {
        long long p = ts.first;//thừa số
        int e = ts.second;//số mũ
        long long demP = dem(n, p);
        minM = min(minM, demP / e);
    }
    return minM;
}

int main() {
    int soTest;
    cin >> soTest;
    while (soTest--) {
        long long N, K;
        cin >> N >> K;
        cout << timMMax(N, K) << '\n';
    }
    return 0;
}
/*Giả sử N!=a^x.b^y.c^z. R
K = a^x1.b^x2.c^x3 --> K^M = a^Mx1.b^Mx2.c^Mx3
Để N! chia hết cho K^M thì Mx1<=x, Mx2<=y, Mx3<=z
-->M<=x1/x1, M<=y/x2, M<=z/3
M nguyên--> M<=[
-->M <= min([x1/x1],[y/x2], [z/x3])
Dấu bằng xảy ra M đạt GTLN = min([x1/x1],[y/x2], [z/x3])
*/