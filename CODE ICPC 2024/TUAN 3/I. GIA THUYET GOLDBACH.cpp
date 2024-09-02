#include<bits/stdc++.h>
using namespace std;

int a[1000005];

void era(){
	for(int i=0;i<1000005;i++)a[i]=1;
	a[1]=a[0]=0;
	for(int i=0;i<=sqrt(1000005);i++){
		if(a[i]==1){
			for(int j=i*i;j<=1000005;j+=i) a[j]=0;
		}
	}
}

int main(){
    era();
	int n;
	cin>>n;
	long long cnt = 0;
	for(int i = 2;i<=n/2;i++){
		if(a[i]==1&&a[n-i]==1) cnt++;
	}
	cout<<cnt;
}