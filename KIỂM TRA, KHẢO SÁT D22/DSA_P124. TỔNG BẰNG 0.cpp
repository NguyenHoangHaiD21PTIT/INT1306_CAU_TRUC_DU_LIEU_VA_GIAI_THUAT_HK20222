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
        //sum: a[1] + a[2] + ... + a[i]
        sum += a[i];
        //mp[sum]: Số lượng chỉ số j phân biệt < i sao cho tổng: a[1] + a[2] + ... + a[j] bằng sum 
        cnt += mp[sum];
        //Ghi nhận là có thêm 1 index i nữa mà a[1] + a[2] + ... + a[i] = sum
        mp[sum]++;
    }
    cout << cnt;
}
