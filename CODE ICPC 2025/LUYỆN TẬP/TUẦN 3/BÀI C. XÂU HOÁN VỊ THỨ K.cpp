#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; int k; 
    cin >> s >> k;
    sort(s.begin(), s.end());
    if(k == 1){
        cout << s << endl;
        return 0;
    }
    int cnt = 1;
    while(next_permutation(s.begin(), s.end())){
        cnt++;
        if(cnt == k){
            cout << s << endl;
            return 0;
        }
    }
}