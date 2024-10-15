#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < m) a[i] = -1;  
        else if (a[i] == m) a[i] = 0; 
        else a[i] = 1; 
    }
    long long cnt = 0;
    unordered_map<long long, long long> pre[2]; // 0 cho chẵn, 1 cho lẻ
    pre[0][0] = 1; 
    long long sum = 0, cntM = 0; 
    for (int i = 1; i <= n; i++) {
        sum += a[i]; 
        if (a[i] == 0) cntM++; 
        if (cntM % 2 == 0) cnt += pre[1][sum]; 
        else cnt += pre[0][sum]; 
        pre[cntM % 2][sum]++; 
    }
    cout << cnt; 
}
