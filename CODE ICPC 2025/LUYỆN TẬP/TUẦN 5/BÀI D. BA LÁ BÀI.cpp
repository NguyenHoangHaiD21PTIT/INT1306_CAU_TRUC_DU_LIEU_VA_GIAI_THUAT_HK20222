#include <bits/stdc++.h>
using namespace std;
bool cmp1(string a, string b) {
    if (a.size() != b.size()) return a.size() > b.size(); 
    return a > b; 
}
bool cmp2(string a, string b){
    return a + b > b + a;
}
int main() {
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp1);
    vector <string> v1;
    v1.push_back(v[0]); v1.push_back(v[1]); v1.push_back(v[2]); 
    sort(v1.begin(), v1.end(), cmp2);
    cout << v1[0] + v1[1] + v1[2];
}
