#include<bits/stdc++.h>
using namespace std;

int main(){
    int t = 1, n, k;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n];
        for(int &i : a) 
			cin >> i;
        int MAX[n], ans = -1;
        MAX[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; --i) 
			MAX[i] = max(MAX[i + 1], a[i]);
        int i, j;
        i = j = 0;
        while(i < n and j < n){
            if(MAX[j] > a[i]){
                ans = max(ans, j - i);
                ++j;
            }
            else 
				++i;
        }
        if(!ans) 
			ans = -1;
        cout << ans << endl;
    }
    return 0;
}
