#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int K, B, M;
    cin >> s;
    cin >> K >> B >> M;//K: Độ dài sliding window, B: hệ cơ số, M: Số chia dư

    int n = s.length();
    // Tính giá trị đặc biệt của xâu con đầu tiên có độ dài K
    int cur = 0;
    for (int i = 0; i < K; ++i) cur = (cur * B + (s[i] - '0')) % M;
    int sum = cur;

    //Tính B^(K-1) mod M
    int tmp = 1;
    for(int i = 1;i<=K -1;i++) tmp = (tmp * B) % M;

    //Các cửa số trượt
    for (int i = K; i < n; ++i) {
        cur = (cur - (s[i - K] - '0') * tmp % M + M) % M;
        cur = (cur * B + (s[i] - '0')) % M;
        sum += cur;
    }
    cout << sum << endl;

}
