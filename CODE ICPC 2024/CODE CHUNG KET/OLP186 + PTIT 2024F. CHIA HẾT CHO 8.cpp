#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    if (s.size() == 1 && s == "8") {
        return true;
    } else if (s.size() == 2) {
        int x = stoi(s);
        int x1 = (s[1] - '0') * 10 + (s[0] - '0');
        if (x % 8 == 0 || x1 % 8 == 0) return true;
    } else {
        int cnt[10] = {};
        for (char x : s) cnt[x - '0']++;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    int num = i * 100 + j * 10 + k;
                    if (num % 8 == 0) {
                        int needed[10] = {};
                        needed[i]++; needed[j]++; needed[k]++;
                        bool possible = true;
                        for (int d = 0; d <= 9; d++) {
                            if (needed[d] > cnt[d]) {
                                possible = false;
                                break;
                            }
                        }
                        if (possible) return true; 
                    }
                }
            }
        }
    }
    return false; 
}

int main() {
    string s;
    cin >> s;
    if (check(s)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
