#include<bits/stdc++.h>
using namespace std;

int n, k, a[100], b[100], ok;//ok: con sinh duoc

void kt(){ //khoi tao cau hinh dau tien
	for(int i=0;i<k;i++){
		a[i] = i+1;
	}
}

void sinh(){
	// Tim vi tri dau tien chua bang GTLN = n - k + (i+1)
	int i = k-1;
	while(i>=0&&a[i]==n - k + (i+1)){
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		a[i]++;
		for(int j = i+1;j<k;j++){
			a[j] = a[j-1] + 1;
		}
	}
}

int check(){
	for(int i=0;i<k;i++){
		if(a[i]!=b[i])  return 0;
	}
	return 1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ok=1;
		for(int i=0;i<k;i++){
			cin>>b[i];
		}
		kt();
		int ans = 0;
		if(check()==1){
			ans = 1;
		} else {
			ans = 1;
			while(ok==1){
				sinh();
				ans++;
				if(check()==1) break;
			}
		}
		cout<<ans<<endl;
	}
}