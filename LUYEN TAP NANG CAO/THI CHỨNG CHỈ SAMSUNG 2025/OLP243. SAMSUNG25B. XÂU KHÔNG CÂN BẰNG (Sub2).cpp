#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, k;
string s;

// Kiểm tra bitmask len ký tự có palindrome không
bool pal(int mask, int len) {
    for (int i = 0; i < len / 2; i++) {
        int left  = (mask >> i) & 1;
        int right = (mask >> (len - 1 - i)) & 1;
        if (left != right) return false;
    }
    return true;
}

long long dp[1001][512];

// Gọi trạng thái là bitmask state biểu diễn K−1 kí tự cuối (A = 0, B = 1). 
// Gọi dp[i][state] là số lượng xâu thỏa mãn khi duyệt tới kí tự thứ i và có K - 1 kí tự cuối bằng state. 

int main() {
    cin >> n >> k >> s;
    int stmax = 1 << (k - 1);
    dp[0][0] = 1; 
    for (int i = 1; i <= n; i++) {
        for (int st = 0; st < stmax; st++) { //K - 1 ký tự cuối của xâu dài i - 1
            if (dp[i - 1][st] == 0) continue;
            vector<int> ch;
            // Lấy ký tự hiện tại để ta thêm vào bitmask
            if (s[i - 1] == 'A') ch = {0};
            else if (s[i - 1] == 'B') ch = {1};
            else ch = {0, 1}; // '?'
            for (int b : ch) {
                int ns = ((st << 1) & (stmax - 1)) | b;
                //st << 1: dịch bitmask sang trái 1 bit để nhường chỗ cho ký tự hiện tại, giữ K - 1 bit cuối, sau đó thêm ký tự hiện tại vào vị trí thấp nhất.
                if (i >= k && pal((st << 1) | b, k)) continue;
                dp[i][ns] = (dp[i][ns] + dp[i - 1][st]) % MOD;
            }
        }
    }
    long long ans = 0;
    for (int st = 0; st < stmax; st++) ans = (ans + dp[n][st]) % MOD;
    cout << ans;
}
