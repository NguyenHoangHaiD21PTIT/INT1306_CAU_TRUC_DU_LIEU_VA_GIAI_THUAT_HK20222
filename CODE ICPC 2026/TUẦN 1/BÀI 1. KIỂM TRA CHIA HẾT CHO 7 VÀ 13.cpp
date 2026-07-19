#include<bits/stdc++.h>
using namespace std;

int r (string s, int m){ //s % m
    int res = 0;
    for(char x: s) res = (res * 10 + (x - '0')) % m;
    return res;
}

int main(){
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int r7 = r(s, 7), r13 = r(s, 13);
        if (!r7 && !r13) cout << "Both" << endl;
        else if (!r7) cout << "Div 7" << endl;
        else if (!r13) cout << "Div 13" << endl;
        else cout << "None" << endl;
    }
}