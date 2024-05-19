#include<bits/stdc++.h>
using namespace std;
int n, a[100], ok;
void kt(){
	for(int i=0;i<n;i++){
		a[i]=n-i;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		kt();
		int gt = 1;
		for(int i=1;i<=n;i++) gt*=i;
		//In cau hinh dau tien
		for(int i=0;i<n;i++){
			cout<<a[i];
		}
		cout<<",";
		int cnt = 1;
		//Kiem tra con sinh duoc tiep hay khong roi in tiep
		while(prev_permutation(a,a+n)!=false){
			cnt++;
			for(int i=0;i<n;i++){
				cout<<a[i];
			}
			if(cnt!=gt)
			cout<<",";
		}
		cout<<endl;
	}
}
