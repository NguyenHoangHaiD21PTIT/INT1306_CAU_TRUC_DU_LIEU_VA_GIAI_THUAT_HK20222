#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		int cnt[50]={};
		for(int i=a;i<=b;i++){
			int tmp = i;
			while(tmp>0){
				cnt[tmp%10]++;
				tmp/=10;
			}
		}
		for(int i=0;i<=9;i++) cout<<cnt[i]<<" ";
		cout<<endl;
	}
}