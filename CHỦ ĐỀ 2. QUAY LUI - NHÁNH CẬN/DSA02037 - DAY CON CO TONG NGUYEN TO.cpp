#include<bits/stdc++.h>
using namespace std;

//SINH XAU NHI PHAN NGUOC
int n, a[100], ok, b[100];//Mang a: Mang nhi phan, mang b: Mang so ban dau
//a[i]=1 tuc la lay phan tu b[i] ra va nguoc lai

void kt(){
	for(int i=0;i<n;i++){
		a[i] = 0;
	}
}

void sinh(){
	int i = n -1;
	while(i>=0&&a[i]==1){
		a[i] = 0;
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		a[i] = 1;
	}
}

//Kiem tra dieu kien nguyen to
int check(int x){
	if(x<=1){
		return 0;
	} else {
		for(int i=2;i<=sqrt(x);i++){
			if(x%i==0) return 0;
		}
		return 1;
	}
			
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		kt();
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		sort(b,b+n, greater<int>());
		ok=1;
		while(ok==1){
			string s = "";
			int tong = 0;
			for(int i=0;i<n;i++){
				if(a[i]==1) tong+=b[i];
			}
			//Chi lay cac tong nguyen to
			if(check(tong)==1){
				for(int i=0;i<n;i++){
					if(a[i]==1) cout<<b[i]<<" " ;
				}
				cout<<endl;
			}
			sinh();
		}
	}
}
//2 3 4 5