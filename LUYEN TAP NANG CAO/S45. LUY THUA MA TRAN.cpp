#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n;
struct matrix{
    long long a[15][15];
};

matrix mul(matrix A, matrix B){
    matrix res;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++) res.a[i][j] = 0;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++) res.a[i][j] = (res.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
        }
    }
    return res;
}

matrix powMod(matrix A, long long p){
    if(p==1) return A;
    matrix tmp = powMod(A, p/2);
    matrix ans = mul(tmp, tmp);
    if(p%2) ans = mul(ans, A);
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int k; cin>>k;
        matrix A;
        for(int i =1;i<=n;i++){
            for(int j = 1;j<=n;j++) cin>>A.a[i][j];
        }
        A = powMod(A, k);
        long long ans = 0;
        for(int i = 1;i<=n;i++) ans = (ans + A.a[i][n]) % MOD;
        cout<<ans<<endl;
    }
}
