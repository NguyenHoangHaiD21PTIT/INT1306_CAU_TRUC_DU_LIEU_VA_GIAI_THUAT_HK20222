#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; string s;
    cin>>n>>s;
    s = " " + s;
    string q = "RGB";
    int dp[100][4005];//dp[i][j]: số lần xuất hiện chữ cái i tính đến index j
    for(int i = 1;i<=n;i++){
        for(char x: q) dp[int(x)][i] = dp[int(x)][i - 1] + (x == s[i]);
    }
    long long ans = 0;
    for(int i = 1;i<=s.size();i++){
        for(int j = i + 1;j<=s.size();j++){
            if((s[i]=='R'&&s[j]=='G') || (s[i]=='G'&&s[j]=='R')) ans+=dp[int('B')][n] - dp[int('B')][j - 1] - (s[2 * j - i] == 'B');
            if((s[i]=='G'&&s[j]=='B') || (s[i]=='B'&&s[j]=='G')) ans+=dp[int('R')][n] - dp[int('R')][j - 1] - (s[2 * j - i] == 'R');
            if((s[i]=='R'&&s[j]=='B') || (s[i]=='B'&&s[j]=='R')) ans+=dp[int('G')][n] - dp[int('G')][j - 1] - (s[2 * j - i] == 'G');
        }
    }
    cout<<ans;
}
