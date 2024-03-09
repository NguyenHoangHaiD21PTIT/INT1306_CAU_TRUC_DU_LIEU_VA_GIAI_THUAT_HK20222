#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

long long powdu(long long a, long long b){
	long long res=1;
	while(b){
		if(b%2==1){
			res=(res*a)%MOD;
		}
		a=(a*a)%MOD;
		b/=2;
	}
	return res;
}

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		cin>>s;
		string s1 = s;
		reverse(s1.begin(),s1.end());
		long long x1 = stol(s);
		long long x2 = stol(s1);
		if(x1==0){
			cout<<0<<endl;
		} else{
			cout<<powdu(x1,x2)<<endl;
		}
	}
}