#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        s = '1' + s + '1';
        int cnt = 0;
        char pre = '1'; 
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                if (pre == '1') {
                    if (s[i + 1] == '0') {
                        cnt += 2; 
                        i++; 
                    }
                } else {
                    cnt += 1;
                }
                pre = '1'; 
            } else {
                cnt += 1; 
                pre = '0'; 
            }
        }
        cout << n - cnt << endl;
    }
}

