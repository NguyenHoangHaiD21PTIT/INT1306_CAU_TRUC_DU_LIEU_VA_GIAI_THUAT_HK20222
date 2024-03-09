#include<bits/stdc++.h>
using namespace std;

//Mang a: Mang dung de sinh to hop, a[i] = x thi phan tu tai vi tri x-1 cua mang loai trung duoc loi ra
//VD: 1 3 5 --> Loi a1 a3 a5

int n, k, a[100], ok, b[100];//ok: con sinh duoc

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

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		vector<int>v;
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		sort(b,b+n);
		kt();
		ok=1;
		int ans = 0;
		while(ok==1){
			for(int i=0;i<k;i++){
				int pos = a[i] - 1;
				cout<<b[pos]<<" ";
			}
			cout<<endl;
			sinh();
		}
	}
}
