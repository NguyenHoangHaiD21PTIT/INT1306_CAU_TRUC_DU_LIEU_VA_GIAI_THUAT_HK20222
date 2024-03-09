#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		//Lam cho chu so hang cao cang be cang tot
		string s1="", s2="";
		for(int i=0;i<n;i++){
			if(i%2==0){
				s1 = s1 + to_string(a[i]);
			} else {
				s2 = s2 + to_string(a[i]);
			}
		}
		long long x1 = stoll(s1);
		long long x2 = stoll(s2);
		cout<<x1+x2<<endl;
	}
}