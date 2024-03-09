#include<bits/stdc++.h>
using namespace std;

int a[100], ok;

//Sinh chinh hop chap 4 cua 3

//1:+, 2:-, 3:x
void kt(){
	for(int i=0;i<4;i++) a[i] = 1;
}

void sinh(){
	int i = 3;
	while(i>=0&&a[i]==3) i--;
	if(i==-1){
		ok = 0;
	} else {
		a[i]++;
		for(int j=i+1;j<4;j++) a[j] = 1;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int b[5];
		for(int i=0;i<5;i++) cin>>b[i];
		sort(b,b+5);
		kt();
		ok=1;
		int check = 0;
		long long res = b[0];
		for(int i=0;i<4;i++){
			if(a[i]==1){
				res+=b[i+1];
			} else if (a[i]==2){
				res-=b[i+1];
			} else if (a[i]==3){
				res*=b[i+1];
			}
		}
		if(res==23){
			check = 1;
		} else {	
			while(next_permutation(b,b+5)!=false){
				kt();
				ok=1;
				while(ok==1){
				 	res = b[0];	
					for(int i=0;i<4;i++){
						if(a[i]==1){
							res+=b[i+1];
						} else if (a[i]==2) {
							res-=b[i+1];
						} else if (a[i]==3){
							res*=b[i+1];
						}
					}
					if(res==23){
						check = 1;
						break;
					} else {
						sinh();
					}
				}
			}
		}
		if(check==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
