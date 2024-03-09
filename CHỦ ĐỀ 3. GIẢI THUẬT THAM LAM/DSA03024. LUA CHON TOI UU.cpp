#include<bits/stdc++.h>
using namespace std;

struct task{
	int start, finish;
};

bool cmp(task a, task b){
	return a.finish<b.finish;
}

task a[100010];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i].start>>a[i].finish;
		sort(a,a+n,cmp);
		int cnt = 1, kt = a[0].finish;
		for(int i=1;i<n;i++){
			if(a[i].start>=kt){
				cnt++;
				kt = a[i].finish;
			}
		}
		cout<<cnt<<endl;
	}
}