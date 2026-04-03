#include<bits/stdc++.h>
using namespace std;
int n, k, a[100], b[100], ok;

void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i) i--;
    if(!i) ok = 0;
    else {
        a[i]++;
        for(int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
    }
}

int check(){
    for(int i = 1; i <= k; i++){
        if(a[i] != b[i]) return 0;
    }
    return 1;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k; ok = 1;
        for(int i = 1; i <= k; i++) cin >> b[i];
        for(int i = 1; i <= k; i++) a[i] = i; 
        int ans = 1;
        while(ok){
            if(check()) break; 
            sinh(); ans++; 
        }
        cout << ans << endl;
    }
}
