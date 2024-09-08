#include <bits/stdc++.h> 
using namespace std; 
int main() { 
	int a, b, k, cnt = 0;
	cin>>a>>b>>k;
	int c = __gcd(a, b);
	for(int i = c;i>=1;i--){
		if(c%i==0){
			cnt++;
			if(cnt==k){
				cout<<i;
				break;
			}
		}
	}
}
		