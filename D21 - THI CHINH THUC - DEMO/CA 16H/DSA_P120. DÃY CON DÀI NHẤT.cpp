#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m;
    cin >> n >> m;
    ll a[n+5]; ll b[m+5];
    int dp[n+5][m+5];
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    int ans = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) dp[i][j]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] * b[j - 1] == a[i - 1] * b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans,dp[i][j]);
            }
        }
    }
    cout <<ans;
}
