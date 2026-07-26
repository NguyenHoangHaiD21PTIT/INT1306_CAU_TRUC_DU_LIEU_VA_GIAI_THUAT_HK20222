#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    ll s = 0, min_v = 2e9, max_v = -2e9;
    for (int i = 0; i < n; i++){
        cin >> a[i]; s += abs(a[i]);
        min_v = min(min_v, a[i]);
        max_v = max(max_v, a[i]);
    }
    if (n == 1) cout << a[0];
    else if (min_v >= 0) cout << s - 2 * min_v;
    else if (max_v <= 0) cout << s + 2 * max_v;
    else cout << s;
}