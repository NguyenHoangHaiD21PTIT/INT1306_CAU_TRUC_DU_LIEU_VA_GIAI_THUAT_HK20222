#include<bits/stdc++.h>
using namespace std;

int n, k, a[100], b[100];

int check(int x){
	for(int i=0;i<k;i++){
		if(a[i]==x) return 1;
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<k;i++){
			cin>>a[i];
			b[i] = a[i];
		}
		int i = k - 1;//Tim vi tri dau tien chua dat GTLN = n - k + (i+1)
		int ans = 0;//so phan tu moi
		while(i>=0&&b[i]==n-k+(i+1)) i--;
		if(i==-1){ //Cau hinh cuoi
			ans = k;
		} else {
			b[i]++;
			for(int j = i+1;j<k;j++){
				b[j] = b[j-1] + 1;
			}
			for(int p=0;p<k;p++){
				//Ta xem voi moi b[p] thi b[p] co trong mang a khong
				if(check(b[p])==0) ans++;
			}
		}
		cout<<ans<<endl;
	}
}

