#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) c[i] = a[i] - b[i];
    sort(c, c + n, greater<int>());
    long long sum = 0;
    int res = 0;//chiều dài
    for(int i = 0; i < n; i++) {
        if (sum + c[i] >= 0) {
            sum += c[i];
            res++;
        } else {
            break; 
        }
    }
    cout << res;
}

