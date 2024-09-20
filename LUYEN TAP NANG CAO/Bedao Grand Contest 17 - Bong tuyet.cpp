#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<long long, pair<int, int>>mp; //mp[m] = {a, b} nghĩa là a^b = m
    for(int i = 2;i<=1e6;i++){ //Mục tiêu là sinh hết ra các cặp i^d
        long long sum = 1 + i, cur = i;
        for (long long d = 2; sum <= 1e18; d++) {//d: số mũ hiện tại
            if (cur > 1e18 / i) break; // Nhân thêm mà quá --> Bỏ
            cur *= i;
            sum += cur;
            if (sum > 1e18) break;
            if (mp.find(sum) == mp.end()) mp[sum] = {i, d};
        }
    }
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        pair<long long, int>ans = {1e18, 0};//Lưu cơ số và số mũ để cho kết quả tương ứng
        if(mp.find(n)!=mp.end()) ans = mp[n];
        //x > 1e6 thì giải phương trình bậc 2: x^2 + x - n + 1 = 0
        long long delta = 4 * n - 3;
        if(delta >= 0){
            long double x = (-1 + sqrtl(delta)) / 2;   
            long long x1 = round(x);
            if(abs(x1 - x) < 1e-9 && x1>1) ans = min(ans, {x1, 2});
        }
        if (ans.first == 1e18) cout << -1<<endl;
        else cout << ans.first << ' ' << ans.second<<endl;
    }
}