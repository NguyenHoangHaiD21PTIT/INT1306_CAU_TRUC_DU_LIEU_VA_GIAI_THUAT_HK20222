#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int cnt = 0;
        while(true){
            int pos = s.find("()");
            if (pos == -1) break;
            else {
                s.erase(pos, 2);
                cnt+=2;
            }
        }
        cout << cnt << "\n";
    }
}