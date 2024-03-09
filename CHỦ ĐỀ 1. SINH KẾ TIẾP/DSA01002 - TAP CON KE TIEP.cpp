#include<bits/stdc++.h>
using namespace std;
int n, a[1000], k;
void sinh(){
	int i=k;
	while(i>=1&&a[i]==n-k+i){
		i--;
	}
	if(i!=0){//cau hinh chua phai cuoi cung
		a[i]++;
		for(int j=i+1;j<=k;j++){
			a[j]=a[j-1]+1;
		}
	} else {//cau hinh cuoi --> quay nguoc len dau
		for(int i=1;i<=k;i++){
			a[i]=i;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i];
		}
		sinh();
		for(int i=1;i<=k;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}