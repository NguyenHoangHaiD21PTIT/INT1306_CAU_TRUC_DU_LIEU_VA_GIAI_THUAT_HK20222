#include<bits/stdc++.h>
using namespace std;

int cnt[100050]={};

bool cmp(int x, int y){
	if(cnt[x]!=cnt[y]){
		return cnt[x]>cnt[y];
	}
	return x<y;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			cnt[a[i]]++;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}