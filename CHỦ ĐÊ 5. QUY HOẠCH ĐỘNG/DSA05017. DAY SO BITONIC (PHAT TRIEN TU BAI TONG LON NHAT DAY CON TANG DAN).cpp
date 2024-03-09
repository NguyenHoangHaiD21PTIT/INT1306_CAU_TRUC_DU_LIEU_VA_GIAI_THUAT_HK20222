#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int inc[n], dec[n], bin[n];
		for(int i=0;i<n;i++) inc[i] = dec[i] = a[i];
		//Tim tong lon nhat cua day con tang dan ket thuc tai chi so i
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[j]<a[i]) inc[i] = max(inc[i], inc[j] + a[i]);
			}
		}
		//Tim tong lon nhat cua day con giam dan bat dau tu chi so i
		for(int i = n-1;i>=0;i--){
			for(int j = n-1;j>i;j--){
				if(a[j]<a[i]) dec[i] = max(dec[i], dec[j] + a[i]);
			}
		}
		//Day so Bitonic dinh i = day con tang dan ket thuc tai chi so i + day con giam dan bat dau tai i
		for(int i=0;i<n;i++) bin[i] = inc[i] + dec[i] - a[i];
		cout<<*max_element(bin, bin+n)<<endl;
	}
}