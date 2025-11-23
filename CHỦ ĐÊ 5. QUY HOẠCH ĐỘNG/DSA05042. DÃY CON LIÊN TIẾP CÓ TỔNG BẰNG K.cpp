#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t; cin >> t;
    while(t--){
        int n; ll k, sum = 0;
        cin >> n >> k;
        ll a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        map<ll, bool>mp;
        //mp để lưu các tổng từ 0 đến i, với i đi từ 0 đến n - 1
        //mp lưu các tổng: Từ 0 đến 1, Từ 0 đến 2, ..., Từ 0 đến n
        int check = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];
            //mp[sum - k] = true --> Tồn tại 1 chỉ số j sao cho tổng từ 0 đến j = sum - k
            /*[0 ...... j] [j + 1 j + 2 .... i]
                 sum - k  +        x           = sum --> x = k*/
            if(sum == k|| mp[sum - k]){
                check = 1;
                cout << "YES" << endl;
                break;
            }
            mp[sum] = true;
        }
        if(!check) cout << "NO" << endl;
    }
}
