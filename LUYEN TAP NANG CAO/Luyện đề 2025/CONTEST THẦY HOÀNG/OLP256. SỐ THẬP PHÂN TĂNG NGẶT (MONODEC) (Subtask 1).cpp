#include <bits/stdc++.h>
using namespace std;
bool check(int n){
    string s = to_string(n);
    if (s.length() == 1) return true;
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] >= s[i + 1]) return false;
    }
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = n; i >= 0; i--){
            if (check(i)){
                cout << i << endl;
                break;
            }
        }
    }
}