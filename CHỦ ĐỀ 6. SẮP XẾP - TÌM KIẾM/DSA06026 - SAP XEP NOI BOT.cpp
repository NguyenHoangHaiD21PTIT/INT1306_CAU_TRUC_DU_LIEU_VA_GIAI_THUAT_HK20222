#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	//Voi moi mot buoc, ta se xet 2 cap so ke nhau va duyet den vi tri so dau tien chua duoc sx
	for(int i=0;i<n;i++){ //Buoc thu i
		int idx = n - i - 1; //Sau buoc thu i se co i so duoc sx
		int check = 0; //Kiem tra buoc do can SX nua hay thoi
		for(int j=0;j<idx;j++){
			if(a[j]>a[j+1]){
				check = 1;
				swap(a[j],a[j+1]);
			}
		}
		if(check==1){
			cout<<"Buoc "<<i+1<<": ";
			for(int p: a) cout<<p<<" ";
			cout<<endl;
		} else {
			break;
		}
	}
}