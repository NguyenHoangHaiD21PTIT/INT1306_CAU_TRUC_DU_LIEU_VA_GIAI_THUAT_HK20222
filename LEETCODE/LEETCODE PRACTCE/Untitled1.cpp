#include<bits/stdc++.h>
using namespace std;

int main(){
    int t = 1, n;
    while(t--){
        cin >> n;
        vector<int> a(n + 5), f(n + 5, 0);
        for(int i = 1; i <= n; i++) 
			cin >> a[i];
        int res = 0;
        for(int i = 1; i <= n; i++){
            f[a[i]] = f[a[i] - 1] + 1;
            res = max(res, f[a[i]]);
            cout<<f[a[i]]<<" ";
        }
        cout << n - res;
    }
    return 0;
}