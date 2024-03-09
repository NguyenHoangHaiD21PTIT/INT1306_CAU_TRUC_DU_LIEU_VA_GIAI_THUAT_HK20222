#include<bits/stdc++.h>
using namespace std;

long long pow(long long a, long long b){
    long long res = 1;
    while(b){
        if(b%2==1) res = (res*a);
        a = (a*a);
        b/=2;
    }
    return res;
}

long long trans(string s){
	long long tong = 0;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') tong+=pow(2,i);
	}
	return tong;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s1, s2;
		cin>>s1>>s2;
		long long x1 = trans(s1);
		long long x2 = trans(s2);
		cout<<x1*x2<<endl;
	}
}