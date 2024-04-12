#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n = s.size();
		int f[n];
		for(int i=0;i<n;i++) f[i] = 1;
		for(int i=0;i<n;i++){
			for(int j = 0;j<i;j++){
				if(tolower(s[j])<tolower(s[i])) f[i] = max(f[i],f[j]+1);
			}
		}
		cout<<*max_element(f,f+n)<<endl;
	}
}