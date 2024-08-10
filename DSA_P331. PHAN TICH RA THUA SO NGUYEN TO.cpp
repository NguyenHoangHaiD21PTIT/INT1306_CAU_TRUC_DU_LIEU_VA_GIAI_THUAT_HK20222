#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        map<long long, long long>mp;
        long long n;
        cin>>n;
        for(int i = 2;i<=sqrt(n);i++){
            if(n%i==0){
                long long dem = 0;
                while(n%i==0){
                    n/=i;
                    dem++;
                }
                mp[i] = dem;
            }
        }
        if(n!=1) mp[n] = 1;
        for(auto x: mp) cout<<x.first<<" "<<x.second<<endl;
        cout<<endl;
    }
}