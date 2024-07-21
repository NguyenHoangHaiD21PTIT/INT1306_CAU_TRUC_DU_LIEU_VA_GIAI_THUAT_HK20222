#include<bits/stdc++.h>
using namespace std;

//Mang a: Mang dung de sinh to hop, a[i] = x thi phan tu tai vi tri x-1 cua mang loai trung duoc loi ra
//VD: 1 3 5 --> Loi s0 s2 s4

int n, k, a[100], ok;//ok: con sinh duoc

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
	cin>>n;
	int b[n];
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	k = 2;
	set<string>st;
	while(k<=n){
		kt();
		ok=1;
		while(ok==1){
			string s = "";
			int check = 1;
			for(int i=0;i<k-1;i++){
				int val1 = a[i] - 1;
				int val2 = a[i+1] - 1;
				if(b[val1]>b[val2]){
					check = 0;
					break;
				} else {
					s = s + to_string(b[val1]) + " ";
				}
			}
			if(check==1){
				s = s + to_string(b[a[k-1]-1]);
				st.insert(s);
			}
			sinh();
		}
		k++;
	}
	for(auto i: st) cout<<i<<endl;
}