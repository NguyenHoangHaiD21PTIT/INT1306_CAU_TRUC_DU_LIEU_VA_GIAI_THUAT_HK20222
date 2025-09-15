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

int main() {
    int t; cin >> t;
    while(t--){
        int a, b, cnt = 0; cin >> a >> b;
        for(int i = a; i <= b; i++){
            if(check(i)) cnt++;
        }
        cout << cnt << endl;
    }
}
