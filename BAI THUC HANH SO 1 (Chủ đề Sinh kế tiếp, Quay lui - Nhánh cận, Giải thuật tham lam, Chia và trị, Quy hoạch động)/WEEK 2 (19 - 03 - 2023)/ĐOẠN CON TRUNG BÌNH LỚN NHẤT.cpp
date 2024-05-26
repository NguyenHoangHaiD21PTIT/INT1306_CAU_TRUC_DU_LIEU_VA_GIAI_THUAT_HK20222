#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    a.push_back(-1);
    int l_final = 0, l_tmp = 0, Max = *max_element(a.begin(), a.end());
    for (int i = 0; i <= n; ++i) {
        if (a[i] == Max) {
            l_tmp++;
        } else {
            l_final = max(l_final, l_tmp);
            l_tmp = 0;
        }
    }
    cout << l_final << endl;
    return 0;
}
