#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    long long a[n+5]; long long b[m+5];
    int dp[n+5][m+5];
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    //dp[i][j] là độ dài dãy con dài nhất của cả 2 mảng, kết thúc tại index i của mảng A, index j của mảng B mà các cặp phần tử tương ứng tạo thành dãy tỉ só bằng nhau
    int ans = 1;
    //Mỗi cặp a[i], b[j] tự thân nó đã là một dãy tỉ số bằng nhau với độ dài là 1
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) dp[i][j]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // Mở rộng dãy con từ (i-1, j-1)
            if(a[i] * b[j - 1] == a[i - 1] * b[j]) dp[i][j]=dp[i-1][j-1]+1;
            ans=max(ans,dp[i][j]);   
        }
    }
    cout <<ans;
}
