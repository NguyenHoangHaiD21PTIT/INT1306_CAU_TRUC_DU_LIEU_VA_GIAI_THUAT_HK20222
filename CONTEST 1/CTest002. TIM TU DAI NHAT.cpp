#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, ans = "";
    int Max = 0; 
    while(cin >> s){
        if(s.size() > Max){
            Max = s.size();
            ans = s;
        }
    }
    cout << ans << " - " << Max << endl; 
    return 0;
}
