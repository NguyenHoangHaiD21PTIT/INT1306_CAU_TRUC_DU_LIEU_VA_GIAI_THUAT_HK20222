#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n;
        cin>>n;
        if(!n) break;
        vector<int>a;
        a.push_back(n);
        while(n!=1){
            if(n%2==0) n/=2;
            else n = n * 3 + 1;
            a.push_back(n);
        }
        for(int x: a) cout<<x<<" ";
        cout<<endl;
        cout<<a.size()<<endl;
    }
}