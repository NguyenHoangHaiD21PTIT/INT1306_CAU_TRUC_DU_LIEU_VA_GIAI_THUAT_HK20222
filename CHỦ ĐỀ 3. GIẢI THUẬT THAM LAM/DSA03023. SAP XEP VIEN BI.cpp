#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	string a; cin >> a;
	int cntx = 0;
	for(int i=0; i<n; i++){
		if(a[i] == 'X') ++cntx;
	}
	int res = 0;
	for(int i=0; i<cntx; i++){
		if(a[i] == 'T'){
			for(int j=cntx; j<n; j++){
				if(a[j] == 'X'){
					swap(a[i], a[j]);
					++res;
					break;
				}
			}
		}else if(a[i] == 'D'){
			for(int j=n-1; j>i; j--){
				if(a[j] == 'X'){
					swap(a[i], a[j]);
					++res;
					break;
				}
			}
		}
	}
	for(int i = cntx; i<n; i++){
		if(a[i] == 'D'){
			for(int j=n-1; j>i; j--){
				if(a[j] == 'T'){
					swap(a[i], a[j]);
					++res;
					break;
				}
			}
		}
	}
	cout << res;
}
