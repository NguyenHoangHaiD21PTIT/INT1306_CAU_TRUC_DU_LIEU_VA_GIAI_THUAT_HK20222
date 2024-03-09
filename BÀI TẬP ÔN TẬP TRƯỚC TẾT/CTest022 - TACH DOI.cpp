#include<bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b){
	return a*b/__gcd(a,b);
}
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		cin>>s;
		int p = s.size();
		if(p%2==1){
			cout<<"INVALID"<<endl;
		} else {
			int p1=p/2;
			string s1 = s.substr(0, p1);
			string s2 = s.substr(p1);
			long long x1=stoll(s1);
			long long x2=stoll(s2);
			cout<<lcm(x1,x2)<<endl;
		}
	}
}