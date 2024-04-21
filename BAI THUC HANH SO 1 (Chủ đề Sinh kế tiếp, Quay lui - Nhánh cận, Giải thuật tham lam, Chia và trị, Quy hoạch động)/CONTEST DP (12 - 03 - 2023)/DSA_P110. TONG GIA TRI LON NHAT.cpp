#include<bits/stdc++.h>
using namespace std;

struct object{
	int wei, val;
};

object a[60000];
int dp[6000][6000];

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].wei>>a[i].val;
    int res;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(j < a[i].wei) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].wei] + a[i].val);
            res = max(res, dp[i][j]);
        }
    }
    cout<<res;
}
