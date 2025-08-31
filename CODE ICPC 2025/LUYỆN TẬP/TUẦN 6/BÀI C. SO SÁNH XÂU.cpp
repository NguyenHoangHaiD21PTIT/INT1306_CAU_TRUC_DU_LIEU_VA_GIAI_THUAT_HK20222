#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B; cin >> A >> B;
    string s1(B, '0' + A), s2(A, '0' + B);
    cout << (s1 < s2 ? s1 : s2);
}
