#include <bits/stdc++.h>
using namespace std;
int main() {
    char x, y;
    cin >> x >> y;
    if (x > y)swap(x, y);
    vector<char>v;
    for(char i = x;i<=y;i++) v.push_back(i);
    string s;
    for(char x: v) cout<<x;
    cout<<endl;
    while(next_permutation(v.begin(), v.end())){
        for(char x: v) cout<<x;
        cout<<endl;    
    }
    return 0;
}
