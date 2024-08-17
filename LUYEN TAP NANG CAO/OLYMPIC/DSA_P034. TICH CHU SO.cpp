#include<bits/stdc++.h>
using namespace std;

string minNum(long long p){
    if(p==1) return "1";
    vector<int>v;
    for(int i = 9;i>=2;i--){
        if(p%i==0){
            while(p%i==0){
                v.push_back(i);
                p/=i;
            }
        }
    }
    if(p==-1) return "-1";
    else{
        string res = "";
        for(int x: v) res+=to_string(x);
        reverse(res.begin(), res.end());
        return res;
    }
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long p;
		cin>>p;
		cout<<minNum(p)<<endl;
	}
}
