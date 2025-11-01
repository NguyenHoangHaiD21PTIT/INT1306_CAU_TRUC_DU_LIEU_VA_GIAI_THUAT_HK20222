#include <bits/stdc++.h>
using namespace std;
vector<int> ans(1000001);
bool check(int n){
    string s = to_string(n);
    if (s.length() == 1) return true;
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] >= s[i + 1]) return false;
    }
    return true;
}
void pre(){
    int x = 0;
    for(int i = 0; i <= 1000000; i++){
        if(check(i)) x = i;
        ans[i] = x;
    }
}
int main(){
    int t; cin >> t; pre();
    while(t--){
        int n; cin >> n;
        cout << ans[n] << endl;
    }
}
