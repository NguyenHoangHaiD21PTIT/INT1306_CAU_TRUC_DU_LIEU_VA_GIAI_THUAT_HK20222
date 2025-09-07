#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n; cin >> n;
    string s; cin >> s;
    ll cnt = 1, res = 0;
    for(int i = 1; i < n; i++){
        if (s[i] == s[i - 1]) cnt++;
        else{
            res += (cnt - 1) * cnt / 2;
            cnt = 1;
        }
    }
    res += (cnt - 1) * cnt / 2;
    cout << res;
}
