#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, BASE = 31; //Trong bài này ta sẽ dùng hệ cơ số 31
int main() {
    string s, s1;
    cin >> s >> s1;
    int n = s.size(), m = s1.size();
    vector<long long> Hash(n), Pow(m + 1);
    // 1. Tính k: Hash của s1. Trong bài ta dùng 0 - based
    long long k = 0;
    for (int i = 0; i < m; ++i) k = (k * BASE + (s1[i] - 'a' + 1)) % MOD;
    // 2. Hash[i]: Hash của xâu con [s0 s1 ... si]
    Hash[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < n; ++i) Hash[i] = (Hash[i - 1] * BASE + (s[i] - 'a' + 1)) % MOD;
    // 3. Tính BASE ^ i có MOD
    Pow[0] = 1;
    for (int i = 1; i <= m; ++i) Pow[i] = (Pow[i - 1] * BASE) % MOD;
    // 4. Đoạn con đầu tiên có hask đúng bằng hash của s1 --> index xuất hiện chính là 0 (0 - based)
    if (Hash[m - 1] == k) cout << 1 << ' ';
    /* Chỗ này tư duy như prefix sum. Xét các xâu con liên tiếp dài m, bắt đầu từ i
    +) end - i + 1 = m --> end = i + m - 1. end max = n - 1 = i_max + m - 1 --> i_max = n - m
    +) Bình thường, mảng cộng dồn, để tính tổng [start ... end]: pre[end] - pre[start - 1]
    Tuy nhiên đây là trong mảng số, nên loại ta cần bỏ đúng trị số của nó
    Ví dụ như trong số 12345, ta muốn loại đi 12 (Lấy đoạn 45) thì phải lấy: 12345 - 123*10^2 (2 là số chữ số đoạn đang xét) 
    Tức là: Xâu con dài 2, Hash[4] = 12345, 45 thì index bắt đầu là từ 3 (0 - based), Hash[2] = 123
    Như vậy, để ra Hash [3 ... 4] = Hash[4] - Hash[2] * 10^ 2
    Tổng quát, muốn tính Hash [x ... y] = Hash[y] - Hash [x - 1] * BASE ^ (y - x + 1)*/
    for (int i = 1; i <= n - m; ++i) {
        long long curHash = (Hash[i + m - 1] - Hash[i - 1] * Pow[m] % MOD + MOD) % MOD;
        if (curHash == k) cout << i + 1 << ' ';
    }
}		

