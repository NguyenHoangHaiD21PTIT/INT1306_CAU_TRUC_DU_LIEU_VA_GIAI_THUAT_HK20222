#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s[0] == '0'){
            cout << 0 << endl;
            continue;
        }
        int dp[1005] = {};
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= s.size(); ++i){
            if(s[i - 1] > '0') dp[i] = dp[i - 1];
            if(s[i - 2] == '1' or (s[i - 2] == '2' && s[i - 1] < '7')) dp[i] += dp[i - 2];
        }
        cout << dp[s.size()] << endl;
    }
    return 0;
}
