#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    long long n = s.size(), ans = 0;
    for (long long i = 0; i < n; ++i) {
        int d = s[i] - '0';
        if (d % 4 == 0) ans++;
        if (i > 0) {
            int a = s[i - 1] - '0';
            int b = s[i] - '0';
            int last2 = a * 10 + b;
            if (last2 % 4 == 0) ans += i; 
            // ... a[i] a[i - 1]. Nếu a[i] a[i - 1] = xy là số chia hết cho 4 thì mọi xâu chứa hậu tố xy đều chia hết cho 4.
            // Do đó, cố định i. Còn vị trí đầu xâu, ta sẽ chọn bất kỳ vị trí nào từ 0 đến i - 1, tức là có i cách chọn.
        }
    }
    cout << ans;
}
