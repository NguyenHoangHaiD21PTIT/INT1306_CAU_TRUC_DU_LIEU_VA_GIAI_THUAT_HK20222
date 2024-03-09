#include<bits/stdc++.h>
using namespace std;

int a[100], ok;

//Sinh chinh hop chap 3 cua 2

//1:+, 2:-;
void kt(){
	for(int i=0;i<3;i++) a[i] = 1;
}

void sinh(){
	int i = 2;
	while(i>=0&&a[i]==2) i--;
	if(i==-1){
		ok = 0;
	} else {
		a[i]++;
		for(int j=i+1;j<3;j++) a[j] = 1;
	}
}

int main(){
	int b[4];
	for(int i=0;i<4;i++) cin>>b[i];
	kt();
	ok=1;
	int ans = -1e9;
	while(ok==1){
		int res = b[0];
		for(int i=0;i<3;i++){
			if(a[i]==1){
				res+=b[i+1];
			} else if (a[i]==2){
				res-=b[i+1];
			} 
		}
		ans = max(res,ans);
		sinh();
	}
	cout<<ans<<endl;
}
