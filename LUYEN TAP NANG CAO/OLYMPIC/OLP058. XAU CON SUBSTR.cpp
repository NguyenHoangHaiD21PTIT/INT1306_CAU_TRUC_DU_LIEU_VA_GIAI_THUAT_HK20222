#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int BASE = 31; //Trong bài này ta sẽ dùng hệ cơ số 31

int main() {
    string s, s1;
    cin >> s >> s1;
    int n = s.size(), m = s1.size();
    vector<long long> Hash(n), Pow(m + 1);
    long long k = 0;//k: Hash của s1
    for (int i = 0; i < m; ++i) k = (k * BASE + (s1[i] - 'a' + 1)) % MOD;
    //Hash[i]: Hash của xâu con [s0 s1 ... si]
    Hash[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < n; ++i) Hash[i] = (Hash[i - 1] * BASE + (s[i] - 'a' + 1)) % MOD;
    Pow[0] = 1;
    for (int i = 1; i <= m; ++i) Pow[i] = (Pow[i - 1] * BASE) % MOD;
    if (Hash[m - 1] == k) cout << 1 << ' ';
    //Chỗ này tư duy như prefix sum thôi
    //Bắt đầu từ i, dài m thì end sẽ là i + m - 1. Ta sẽ lấy pre[end] - pre[start - 1]
    //Tuy nhiên đây là số, nên loại ta cần bỏ đúng trị số của nó
    //Ví dụ như 1234, ta muốn loại đi 12 thì phải lấy: 12345 - 123*10^2 (2 là số chữ số đoạn đang xét)
    for (int i = 1; i <= n - m; ++i) {
        long long curHash = (Hash[i + m - 1] - Hash[i - 1] * Pow[m] % MOD + MOD) % MOD;
        if (curHash == k) cout << i + 1 << ' ';
    }
}		
