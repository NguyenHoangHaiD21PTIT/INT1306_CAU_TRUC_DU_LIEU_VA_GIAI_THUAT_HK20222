#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, s;//n: so chu so, s: tong cac chu so
	cin>>n>>s;
	int tmp = s;
	vector<int>to(n);
	vector<int>be(n);
	if(s>9*n||(s==0&&n>1)){
		cout<<"-1 -1";
	} else {
		//1. Tim so lon nhat
		for(int i=0;i<n;i++){
			if(s>=9){
				to[i]=9;
				s-=9;
			} else if (s >0){
				to[i]=s;
				s=0;
			} else {
				to[i]=s;
			}
		}
		tmp--;
		//2. Tim so be nhat
		for(int i=n-1;i>=1;i--){
			if(tmp>=9){
				be[i]=9;
				tmp-=9;
			} else if (tmp >0 ){
				be[i]=tmp;
				tmp=0;
			} else {
				be[i]=tmp;
			}
		}
		be[0]=tmp+1;
		//3. In
		for(int i=0;i<n;i++){
			cout<<be[i];
		}
		cout<<" ";
		for(int i=0;i<n;i++){
			cout<<to[i];
		}
		cout<<" ";
	}
}