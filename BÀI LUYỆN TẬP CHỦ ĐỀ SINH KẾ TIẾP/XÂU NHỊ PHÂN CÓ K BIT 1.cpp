#include <bits/stdc++.h>
using namespace std;
string s; int n, ok;
void kt(){
    s = string(n, '0');
}
void sinh(){
    int i = n - 1;
    while (i >= 0 && s[i] == '1') {
        s[i] = '0';
        i--;
    }
    if (i >= 0) s[i] = '1';
    else ok = 0; 
}
int main(){
    int m; cin >> n >> m;
    string tmp = "";
    for (int i = 1; i <= m; i++) tmp += "1";
    kt(); ok = 1;
    while(ok){
        if (s.find(tmp) != string::npos) cout << s << endl;
        sinh();
    }
}
