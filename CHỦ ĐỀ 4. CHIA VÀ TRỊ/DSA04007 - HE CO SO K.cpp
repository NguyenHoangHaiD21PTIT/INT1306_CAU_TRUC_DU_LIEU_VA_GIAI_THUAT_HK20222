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

long long trans1(string s, long long k){ //chuyen xau s tu he k sang he 10
	long long tong = 0;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		tong+=(s[i]-'0')*pow(k,i);
	}
	return tong;
}

string trans2(long long x, long long k){ //chuyen tu he 10 cua so x sang he k
	stack<long long>st;
	while(x!=0){
		st.push(x%k);
		x/=k;
	}
	string s;
	while(st.size()!=0){
		long long x = st.top();
		s = s + to_string(x);
		st.pop();
	}
	return s;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long k;
		cin>>k;
		string s1, s2;
		cin>>s1>>s2;
		long long x1 = trans1(s1, k); //chuyen xau 1 sang he 10
		long long x2 = trans1(s2, k); //chuyen xau 2 sang he 10
		long long res = x1 + x2; //tong 2 xau trong he 10
		string ans = trans2(res,k);
		cout<<ans<<endl;
	}
}