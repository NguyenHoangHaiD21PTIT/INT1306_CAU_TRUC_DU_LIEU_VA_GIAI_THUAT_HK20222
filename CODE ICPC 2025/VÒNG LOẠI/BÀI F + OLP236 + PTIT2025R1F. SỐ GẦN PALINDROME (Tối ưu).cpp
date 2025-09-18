#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
bool check(int x) {
    string tmp = to_string(x);
    int n = tmp.size(), diff = 0;
    for (int i = 0; i < n / 2; i++) { 
        if (tmp[i] != tmp[n - i - 1]) diff++;
        if (diff > 1) return false;  
    }
    return diff <= 1;
}

int f[1000005];
 
int main() {
    int t; cin >> t;
    for(int i = 1; i <= 1000000; i++){
        if(check(i)) f[i] = f[i - 1] + 1;
        else f[i] = f[i - 1];
    }
    while(t--){
        int a, b; cin >> a >> b;
        cout << f[b] - f[a - 1] << endl;
    }
}
