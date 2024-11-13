#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 7;
int f[mxn];
int get(int x) {
    int res = 0;
    while (x < mxn) {
        res += f[x];
        x += x & -x;
    }
    return res;
}
void update(int x) {
    while (x > 0) {
        ++f[x];
        x -= x & -x;
    }
}
int main() {
    int n; cin >> n;
    int a[n + 5];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
            res += get(a[i] + 1);  
            v.push_back(a[i]);
        } else {
            for (int num : v) update(num);  
            v.clear();
        }
    }
    cout << res;
}


