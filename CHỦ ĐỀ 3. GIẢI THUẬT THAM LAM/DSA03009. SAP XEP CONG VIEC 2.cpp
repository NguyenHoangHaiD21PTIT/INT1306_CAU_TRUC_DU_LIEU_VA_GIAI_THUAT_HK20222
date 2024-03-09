#include<bits/stdc++.h>
using namespace std;

struct task{
	long long id, deadline, profit;
};

bool cmp(task a, task b){
	return a.profit>b.profit;
}
task a[10005]; long long used[10005]={};

int main(){
	int t;
	cin>>t;
	while(t--){
	    memset(used,0,sizeof(used));
		long long n;
		cin>>n;
		for(long long i=0;i<n;i++) cin>>a[i].id>>a[i].deadline>>a[i].profit;
		sort(a,a+n,cmp);
		long long res = 0, cnt = 0;
		for(long long i=0;i<n;i++){
			//Uu tien viec co loi nhuan cao thi lam truoc. Cung loi nhuan thi viec deadline truoc lam truoc
			for(long long j = a[i].deadline-1;j>=0;j--){
				if(used[j]==0){
					cnt++;
					res+=a[i].profit;
					used[j] = 1;
					break;
				}
			}
		}
		cout<<cnt<<" "<<res<<endl;
	}
}