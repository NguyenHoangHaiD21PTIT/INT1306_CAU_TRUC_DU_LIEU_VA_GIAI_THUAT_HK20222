#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = stoi(s), k = s.size(), ans = 0;
    set<int>res;
    for(int x1 = 0;x1<=9;x1++){
        for(int x2 = 0;x2<=9;x2++){
            for(int mask = 0;mask<pow(2, k);mask++){
                long long num = 0;
                for(int i = 0;i<k;i++){
                    if(mask&(1<<i)) num = num * 10 + x1;
                    else num = num * 10 + x2;
                    if(num<=n) res.insert(num);
                }
            }
        }
    }
    cout<<res.size() - 1;
}