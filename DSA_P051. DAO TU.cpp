#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string token;
        vector<string>v;
        while(ss>>token) v.push_back(token);
        for(string x: v){
            for(int j = x.size()-1;j>=0;j--) cout<<x[j];
            cout<<" ";
        }
        cout<<endl;
    }
}
