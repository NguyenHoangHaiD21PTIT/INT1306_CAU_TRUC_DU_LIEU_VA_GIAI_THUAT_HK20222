#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, cnt = 0;
    cin >> n;
    int a[n + 5];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    unordered_map<long long, long long> mp;
    mp[0] = 1; 
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += a[i];
        if(mp.find(sum) != mp.end()) cnt += mp[sum];
        mp[sum]++;
    }
    cout << cnt;
}
//Link test: http://csloj.ddns.net/problem/844
//Luyện tập: http://qboj.zapto.org/problem/sumek
