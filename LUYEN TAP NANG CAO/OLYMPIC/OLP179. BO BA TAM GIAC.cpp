#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n;
    cin>>n;
    ll a[n + 5];
    for(ll i = 1;i<=n;i++) cin>>a[i];
    sort(a + 1, a + n + 1);
    ll vuong = 0, tu = 0, nhon = 0, tong = 0;//tổng số tam giác
    ll k = 3;
    for(ll i = 1;i<=n - 2;i++){
        k = i + 2;
        for (ll j = i + 1; j <= n - 1; j++) {
            if (k <= j) k = j + 1;
            while (k <= n && a[k] < a[i] + a[j]) k++;
            tong += (k - j - 1);
        }
    }
    for (ll i = 1; i <= n - 2; i++) {
        k = i + 2;  
        for (ll j = i + 1; j <= n - 1; j++) {
            if (k <= j) k = j + 1;
            while (k <= n && a[k] * a[k] < a[i] * a[i] + a[j] * a[j]) k++;
            if (a[k] * a[k] == a[i] * a[i] + a[j] * a[j]) vuong++;
            nhon += (k - j - 1);
        }
    }
    tu = tong - nhon - vuong;
    cout<<nhon<<" "<<vuong<<" "<<tu;
}
