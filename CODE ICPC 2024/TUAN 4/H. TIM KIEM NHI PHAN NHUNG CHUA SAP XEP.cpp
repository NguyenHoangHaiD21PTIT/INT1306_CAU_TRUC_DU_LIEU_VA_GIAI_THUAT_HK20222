#include <bits/stdc++.h>
using namespace std;
long long bs(long long a[], long long n, long long x){
    long long l = 1, r = n;
    while(l <= r){
        long long m = (l + r) / 2;
        if(a[m] == x) return 1;
        else if(a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return 0;
}
int main(){
    long long n, m, a, c;
    cin >> n >> m >> a >> c;
    long long x[n + 10];
    cin >> x[0];
    for (long long i = 1; i <= n; i++) x[i] = (a * x[i - 1] + c) % m;
    long long kq = 0;
    for (long long i = 1; i <= n; i++) kq += bs(x, n, x[i]);
    cout << kq;
}
