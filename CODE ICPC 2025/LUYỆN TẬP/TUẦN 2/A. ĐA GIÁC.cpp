#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, tong = 0; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        tong += a[i];
    }
    sort(a, a + n);
    if(a[n - 1] < tong - a[n - 1]) cout << "Yes";
    else cout << "No";
}