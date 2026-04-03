#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll f[95];

bool find(ll f[], ll x) {
    for(int i = 0; i < 92; i++) {
        if(f[i] == x) return true;
    }
    return false;
}

int n, a[100], ok;

void sinh(){
    int i = n - 1;
    while(i >= 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == -1) ok = 0;
    else a[i] = 1;
}

int main(){
    f[0] = f[1] = 1;
	for(int i = 2; i <= 91; i++) f[i] = f[i - 1] + f[i - 2];
    cin >> n; ok = 1;
	for(int i = 0; i < n; i++) a[i] = 0; 
    int cnt = 1;
    while(ok){
        if(find(f, cnt)){
            cout << cnt << ": ";
            for(int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;
        }
        cnt++; sinh();
    }
}
