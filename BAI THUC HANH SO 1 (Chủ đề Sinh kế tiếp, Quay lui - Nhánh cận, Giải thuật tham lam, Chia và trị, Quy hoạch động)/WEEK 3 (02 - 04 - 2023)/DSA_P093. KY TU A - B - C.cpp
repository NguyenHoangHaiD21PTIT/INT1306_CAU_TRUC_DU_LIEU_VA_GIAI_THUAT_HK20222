#include <bits/stdc++.h>
using namespace std;

bool check(const string &s) {
    int a = 0, b = 0, c = 0;
    for (char ch : s) {
        if (ch == 'A') ++a;
        else if (ch == 'B') ++b;
        else ++c;
    }
    return a && b && c && a <= b && b <= c;
}

void gen(int len) {
    vector<int> a(len, 1); //Dãy khởi tạo toàn số 1
    string ch = "ABC";
    bool ok = true;
    while (ok) {
        string tmp;
        for (int i : a) tmp += ch[i - 1];
        if (check(tmp)) cout << tmp << '\n';
        int i = len - 1;
        while (i >= 0 && a[i] == 3) --i;
        if (i < 0) ok = false;
        else {
            a[i]++;
            for (int j = i + 1; j < len; j++) a[j] = 1;
        }
    }
}

int main() {
    int n; cin >> n;
    string s = "ABC";
    cout << s << '\n';
    while (next_permutation(s.begin(), s.end())) cout << s << '\n';
    for (int len = 4; len <= n; ++len) gen(len);
}
