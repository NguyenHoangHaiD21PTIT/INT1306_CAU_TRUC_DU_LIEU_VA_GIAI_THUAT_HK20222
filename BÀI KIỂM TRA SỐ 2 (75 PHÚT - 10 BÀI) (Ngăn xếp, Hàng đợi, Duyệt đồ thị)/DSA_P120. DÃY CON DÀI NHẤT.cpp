#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int a[n+5];
    int b[m+5];
    int dp[n+5][m+5];
   //memset(dp,1,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
    }
    int maxx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if((double)a[i]/b[j]==(double)a[i-1]/b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                maxx=max(maxx,dp[i][j]);

            }
        }
    }cout << maxx<< endl;

}
/*
8 9
1 2 3 4 5 6 7 8
2 4 5 8 10 12 14 16 22
*/
