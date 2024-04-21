#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

struct task{
	long long deadline, profit; 
};

bool cmp (task a, task b){
	return a.profit>b.profit;
}
task a[100007]; map<long long, int>mp;

int main(){
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++) cin>>a[i].deadline>>a[i].profit;
	sort(a,a+n,cmp);
	long long ans = 0;
	for(int i=0;i<n;i++){
		for(int j = a[i].deadline - 1;j>=0;j--){
			if(mp[j]==0){
				mp[j] = 1;
				ans+=a[i].profit;
				break;
			}
		}
	}
	cout<<ans<<endl;
}
