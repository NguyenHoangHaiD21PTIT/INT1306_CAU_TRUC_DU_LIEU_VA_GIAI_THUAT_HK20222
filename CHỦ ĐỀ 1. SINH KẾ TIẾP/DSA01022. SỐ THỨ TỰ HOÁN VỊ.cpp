#include<bits/stdc++.h>
using namespace std;
int n, a[100], b[100];

int check(){
    for(int i = 1; i <= n; i++){
        if(a[i] != b[i]) return 0;
    }
    return 1;
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> n; int ans = 1;
        for(int i = 1; i <= n; i++) cin >> b[i];
        for(int i = 1; i <= n; i++) a[i] = i; 
        while(1){
            if(check()) break; 
            next_permutation(a + 1, a + n + 1); ans++; 
        }
        cout << ans << endl;
    }
}
