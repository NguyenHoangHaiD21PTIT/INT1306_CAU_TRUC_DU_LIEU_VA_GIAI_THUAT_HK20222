#include <bits/stdc++.h>
using namespace std;

int n, ok, a[100];
vector<pair<string, int>> v; //Lưu tập con (Dạng String) và tổng

void kt() {
    for (int i = 0; i < n; i++) a[i] = 0;
}

void sinh() {
    int i = n - 1;
    while (i >= 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == -1) ok = 0;
    else a[i] = 1;
}

bool cmp(pair<string, int> &p1, pair<string, int> &p2) {
    if (p1.second != p2.second) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main() {
    int k; cin >> n >> k;
    int b[n];
    for (int i = 0; i < n; i++) cin >> b[i];
    kt(); ok = 1;
    while (ok == 1) {
        int tong = 0;
        string s = "";
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                tong += b[i];  
                s += to_string(i + 1) + " "; //get index
            }
        }
        if (s != "" && tong < k) v.push_back({s.substr(0, s.size() - 1), tong});
        sinh();
    }
    sort(v.begin(), v.end(), cmp);
    for (auto p : v) cout << p.first << endl << "Sum = " << p.second << endl; 
}
