#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    set <string> st;
    while(n--){
        string s; cin >> s;
        st.insert(s);
    }
    string s2; cin >> s2;
    vector <string> v;
    for(auto i: st){
        if (i != s2) v.push_back(i);
    }
    cout << s2 << " ";
    for(auto x: v) cout << x << " ";
    cout << endl;
    while(next_permutation(v.begin(), v.end())){
        cout << s2 << " ";
        for(auto x: v) cout << x << " ";
        cout << endl;
    }
}
