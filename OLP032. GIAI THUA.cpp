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
