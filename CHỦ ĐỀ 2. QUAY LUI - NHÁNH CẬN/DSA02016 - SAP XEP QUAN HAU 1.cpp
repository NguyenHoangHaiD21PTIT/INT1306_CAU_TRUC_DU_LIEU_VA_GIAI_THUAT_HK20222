#include<bits/stdc++.h>
using namespace std;

int n, x[100], cot[100], xuoi[100], nguoc[100], ans=0; //x[i]=j tuc la dat quan hau hang i cot j

void Try(int i){
	for(int j=1;j<=n;j++){
		if(cot[j]==0&&xuoi[i+j-1]==0&&nguoc[n+i-j]==0){
			x[i] = j;
			cot[j]=1;xuoi[i+j-1]=1;nguoc[n+i-j]=1;
			if(i==n){
				ans++;
			} else {
				Try(i+1);
			}
			cot[j]=0;xuoi[i+j-1]=0;nguoc[n+i-j]=0;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ans = 0;
		cin>>n;
		Try(1);
		cout<<ans<<endl;
	}
}
