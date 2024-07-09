#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	cin>>a>>b;
	int cnt = 0;
	vector<int>v(b+5,1);
	for(int i=2;i<=b;i++){
		for(int j=i;j<=b;j+=i) v[j] +=i;
	}
	for(int i=a;i<=b;i++){
		if(v[i]-i>i) cnt++;
	}
	cout<<cnt;
}