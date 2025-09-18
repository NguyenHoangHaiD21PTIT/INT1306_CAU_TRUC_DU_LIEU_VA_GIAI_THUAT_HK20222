#include <bits/stdc++.h>
using namespace std;

string sol(int m) {
    const int L = 200;
    vector<int> pw(L + 1, 1), one(L + 1, 0);//pw[i] = (10^i) % m, one[i] = (11...1 -> i số 1) % m
    for (int i = 1; i <= L; i++) pw[i] = pw[i - 1] * 10 % m;
    for (int i = 1; i <= L; i++) one[i] = (one[i - 1] * 10 + 1) % m;
    for (int len = 1; len <= L; len++) { //Độ dài xâu
        for (int a = 0; a <= len; a++) { //Số chữ số 8 = a
            int b = len - a, A = 8 * one[a] % m, B = 6 * one[b] % m;//A = (88 ... 8 -> i số 8) % m, B = (i số 6) % m
            //Muốn ghép a số 8 và b số 6 thành số, ta phải dịch tráo a số 8 sang 10^b để nhường chỗ cho b số 6
            if ((1LL * A * pw[b] + B) % m == 0) return string(a, '8') + string(b, '6');
        }
    }
    return "-1";
}

int main() {
    int t, m; cin >> t;
    while (t--) {
        cin >> m;
        cout << sol(m) << '\n';
    }
}
//Link submit: https://oj.vnoi.info/problem/luckynum
