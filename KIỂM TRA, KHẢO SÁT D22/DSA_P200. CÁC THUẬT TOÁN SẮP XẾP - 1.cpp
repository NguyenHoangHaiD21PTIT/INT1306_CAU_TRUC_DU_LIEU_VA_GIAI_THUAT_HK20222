#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int cnt[10004] = {};
        while(n --){
            int x; cin >> x;
            cnt[x]++;
        }
        for(int i = 1;i <= 10000; i++){
            while(cnt[i]--) cout << i << " ";
        }
        cout << endl;
    }
}