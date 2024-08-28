#include<bits/stdc++.h>
using namespace std;
void vietThuong(string &s) {
    for (char &c : s) c = tolower(c);  
}

int main() {
    string s; 
    cin >> s;
    vietThuong(s);  
    if(s.size() >= 3 && s.substr(s.size() - 3) == ".py") cout << "yes";
    else cout << "no";
}
