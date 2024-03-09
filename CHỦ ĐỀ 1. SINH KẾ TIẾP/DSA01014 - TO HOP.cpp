#include<bits/stdc++.h>
using namespace std;

//Mang a: Mang dung de sinh to hop, a[i] = x thi phan tu tai vi tri x-1 cua mang duoc loi ra
//VD: 1 3 5 --> Loi a0 a2 a4

int n, k, a[1000], ok;//ok: con sinh duoc

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
	while(1){
		int q, p, s;//p: so phan tu trong 1 bo, q: <=, s: tong
		cin>>q>>p>>s;
		if(q==0&&p==0&&s==0) break;
		if(p>q){
			cout<<0<<endl;
		} else {
			k = p;
			kt();
			vector<int>b;//luu cac so 
			for(int i=1;i<=q;i++){
				b.push_back(i);
			}
			n = b.size(); 
			ok=1;
			long long ans = 0;
			while(ok==1){
				int tong = 0;
				for(int i=0;i<k;i++){
					int val = a[i] - 1;
					tong += b[val];
				}
				if(tong==s) ans++;
				sinh();
			}
			cout<<ans<<endl; 
		}
	}
}
