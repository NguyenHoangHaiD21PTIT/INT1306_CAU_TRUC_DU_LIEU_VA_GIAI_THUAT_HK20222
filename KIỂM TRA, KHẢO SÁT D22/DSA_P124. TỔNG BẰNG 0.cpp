#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; long long cnt = 0;
    cin >> n;
    int a[n + 5];
    for(int i = 1; i <= n; i++) cin >> a[i];
    unordered_map<long long, long long> mp;
    mp[0] = 1; 
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += a[i];
        cnt += mp[sum];
        mp[sum]++;
    }
    cout << cnt;
}

