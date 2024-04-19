#include<bits/stdc++.h>
using namespace std;

struct line{
	int start, end;
};

bool cmp(line a, line b){
	return a.end<b.end;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		line a[n];
		for(int i=0;i<n;i++) cin>>a[i].start>>a[i].end;
		sort(a,a+n,cmp);
		int cnt = 1, kt = a[0].end;
		for(int i=1;i<n;i++){
			if(a[i].start>=kt){
				cnt++;
				kt = a[i].end;
			}
		}
		cout<<cnt<<endl;
	}
}