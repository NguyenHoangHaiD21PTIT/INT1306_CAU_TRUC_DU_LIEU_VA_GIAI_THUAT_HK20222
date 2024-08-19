#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        set<char>sc;
        for(char x: s) sc.insert(x);
        int st = 0, ans = 1e9, x = 0, a[256] = {};
        for(int i = 0;i<s.size();i++){
            a[s[i]]++;
            if(a[s[i]]==1) x++;
            if(x==sc.size()){
                while(a[s[st]]>1){
                    a[s[st]]--;
                    st++;
                }
                ans = min(ans, i - st + 1);
            }
        }
        cout<<ans<<endl;
    }
}
