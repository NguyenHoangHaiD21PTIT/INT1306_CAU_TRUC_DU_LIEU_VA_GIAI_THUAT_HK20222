#include <bits/stdc++.h>
using namespace std;

int n, ok, a[100];
vector<char> ch; // Lưu các ký tự duy nhất đã được sắp xếp

void sinh() {
    int i = n, k = ch.size(); 
    while (i >= 1 && a[i] == k - 1) i--;
    if (i == 0) ok = 0; 
    else {
        a[i]++;
        for (int j = i + 1; j <= n; j++) a[j] = 0;
    }
}

int main() {
    cin >> n; ok = 1;
    char c; set<char> s;
    for (int i = 0; i < 3; i++) {
        cin >> c;
        s.insert(c);
    }
    for (char x : s) ch.push_back(x);
    for (int i = 1; i <= n; i++) a[i] = 0;
    while (ok) {
        for (int i = 1; i <= n; i++) cout << ch[a[i]];
        cout << endl; sinh();
    }
}
