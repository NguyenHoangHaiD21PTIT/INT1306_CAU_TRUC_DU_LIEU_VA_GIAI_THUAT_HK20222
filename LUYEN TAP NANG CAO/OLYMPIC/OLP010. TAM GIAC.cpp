#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, id = 0, ans = 0;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    set<pair<int, int>>s;
    for(int i = 0;i<n;i++){
        if(s.size()<2) s.insert({a[i], i});
        else{
            while (s.size() > 1) {  
                auto t = ++s.begin();  
                if (t->first + s.begin()->first <= a[i] || s.begin()->first + a[i] <= s.rbegin()->first) {
                    s.erase({a[id], id});  
                    id++; 
                } else break;  
            }
            s.insert({a[i], i});  
            if (s.size() > 2)  ans = max(ans, (int)s.size());  
        }
    }
    cout<<ans;
}
